#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <TinyGPSPlus.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define GPS_RX 17
#define GPS_TX 18
#define OLED_SDA 8
#define OLED_SCL  9
#define SD_CS  10
#define SD_MOSI  11
#define SD_SCK  13
#define SD_MISO  14

#define RECORD_BUTTON  4
#define WAYPOINT_BUTTON  5
#define MENU_BUTTON  6
#define BUZZER  7
#define STATUS_LED  16

const unsigned long ms_interval =500;
bool record =false;
const unsigned long log_interval=1000;
bool details= false;
const unsigned long button_interval =200;

TinyGPSPlus gps;
HardwareSerial gpsSerial(1);
SPIClass sdSpi(FSPI);
Adafruit_SSD1306 display(128, 32, &Wire, -1);


unsigned long lastlog =0;
bool sdready= false;
unsigned long lastdis= 0;

String logfilep;
File logFile;

unsigned long lastbutton =0;
int waypoint =0;

void beep(int dur =50) {
    digitalWrite(BUZZER ,HIGH);
    delay(dur);
    digitalWrite(BUZZER, LOW);
}

String timesta() {
    if (gps.date.isValid() && gps.time.isValid()) {
        char timestamp[25];
        snprintf(timestamp, sizeof(timestamp),"%04d-%02d-%02dT%02d:%02d:%02dZ",gps.date.year(),gps.date.month(),
        gps.date.day(),
        gps.time.hour(), gps.time.minute(),
        gps.time.second());
        return String(timestamp);
    }
    return String(millis());
}

String logrow(const char* event) {
    String row;
    row.reserve(128);
    row +=timesta();
    row+=",";
    if(gps.location.isValid()) {
        row+= String(gps.location.lat(), 6);
        row +=",";
        row+=String(gps.location.lng(),6);
    }else{
        row +=",";
    }
    row+=",";
    if (gps.altitude.isValid()){
        row+=String(gps.altitude.meters(),1);
    }
    row +=",";
    if(gps.speed.isValid()){
        row+=String(gps.speed.kmph(), 1);
    }
    row+=",";
    row+= String(gps.satellites.isValid() ? gps.satellites.value() : 0);
    row +=",";
    row+= event;
    return row;
}


bool writelog(const String& row) {
    if (!sdready|| !logFile){
        return false;
    }
    logFile.println(row);
    logFile.flush();
    return true;
}

String findlog() {
    for (int i = 1; i < 1000; i++){
        char c[16];
        snprintf(c, sizeof(c), "/TRIP%03d.CSV", i);
        if (!SD.exists(c)) {
            return String(c);
        }
    }
    return "";
}

void recordi() {
    if (!sdready ||record) {
        beep(200);
        return;
    }

    logfilep= findlog();
    if(logfilep.isEmpty()){
        return;
    }
    logFile=SD.open(logfilep.c_str(), FILE_WRITE);
    if(!logFile){
        return;
    }
    logFile.println("timestamp,latitude,longitude,altitude_m,speed_kmph,satellites,event");
    logFile.flush();

    record = true;
    writelog(logrow("START"));
    digitalWrite(STATUS_LED , HIGH);
    beep();

    Serial.println("Recording started: " + logfilep);
}

void stoprecord(){
    if(!record){
        return;
    }
    writelog(logrow("STOP"));
    if(logFile){
        logFile.close();
    }
    record =false;
    digitalWrite(STATUS_LED , LOW);
    beep(100);

    Serial.println("Recording stopped");
}

void markway(){
    waypoint++;

    if(record){
        String evename = "WAYPOINT_" + String(waypoint);
        writelog(logrow(evename.c_str()));
    }

    Serial.println("Waypoint " + String(waypoint));
    beep(35);
}

void upddisplay(unsigned long currtime) {
    if(currtime -lastdis< ms_interval){
        return;
    }
    lastdis = currtime;

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print("GPS LOGGER ");
    display.println(record ? "REC" :"READY");

    display.setCursor(0, 12);
    if (details) {
        display.print("SD: ");
        display.print(sdready ? "OK": "ERR");
        display.print(" SAT: ");
        display.println(gps.satellites.isValid() ?gps.satellites.value():0);

        display.setCursor(0,23);
        if (gps.location.isValid()){
            display.print(gps.location.lat(),4);
            display.print(",");
            display.print(gps.location.lng(),4);
        }else{
            display.print("GPS searching");
        }
    }else{
        display.print("GPS: ");
        display.println(gps.location.isValid()?"FIX": "SEARCH");

        display.setCursor(0,23);
        display.print("Speed: ");
        display.print(gps.speed.isValid()?gps.speed.kmph() : 0, 1);
        display.print(" km/h");
    }

    display.display();
}
void readgps(){
    while(gpsSerial.available()){
        gps.encode(gpsSerial.read());
    }
}

void buttonhandle(unsigned long currtime){
    if (currtime -lastbutton<=button_interval) {
        return;
    }

    if(digitalRead(RECORD_BUTTON )==LOW){
        lastbutton=currtime;
        record?stoprecord() :recordi();
    } else if (digitalRead(WAYPOINT_BUTTON ) ==LOW){
        lastbutton =currtime;
        markway();
    } else if(digitalRead(MENU_BUTTON ) == LOW) {
        lastbutton =currtime;
        details =!details;
        beep(25);
    }
}

void handlelog(unsigned long currtime){
    if (!record ||currtime-lastlog<log_interval){
        return;
    }

    lastlog=currtime;
    if(!writelog(logrow("DATA"))) {
        stoprecord();
        Serial.println("SD write failed");
        beep(200);
    }
}
void setup() {
    Serial.begin(115200);

    pinMode(RECORD_BUTTON , INPUT_PULLUP);
    pinMode(WAYPOINT_BUTTON , INPUT_PULLUP);
    pinMode(MENU_BUTTON , INPUT_PULLUP);
    pinMode(BUZZER , OUTPUT);
    pinMode(STATUS_LED ,OUTPUT);
    Wire.begin(OLED_SDA, OLED_SCL );
    display.begin(SSD1306_SWITCHCAPVCC,0x3C);

    gpsSerial.begin(38400, SERIAL_8N1,GPS_RX,GPS_TX);

    sdSpi.begin(SD_SCK, SD_MISO,SD_MOSI,SD_CS );
    sdready = SD.begin(SD_CS, sdSpi, 10000000);

    Serial.println("gps logging started");
    Serial.println(sdready ? "SD ready" :"SD unavailable");

    beep();
}

void loop() {
    const unsigned long currtime = millis();

    readgps();
    buttonhandle(currtime);
    handlelog(currtime);
    upddisplay(currtime);
}

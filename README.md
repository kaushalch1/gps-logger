# gps Logger

## About the Project

this is a gps device designed to record and track journeys without depending on a phone or a constant bluetooth connection.the idea behind this project is to make it easier to collect travel and movement data while hiking or cycling or exploring new places.

the device uses an esp-s3 as its main controller, along with a gps receiver and an oled display, a motion sensor, and a microsd card for storing data. it records information locally so that it can be accessed later, even without an internet connection.


## Tools used

kicad ,github
## how to build it
Step 1 — Solder passive components
Step 2 — Install the ESP32-S3
Step 3 — Install the GPS module
Step 4 — Install the OLED and IMU
Step 5 — Install the microSD socket and controls
Step 6 — Complete power circuitry
St3ep 7-Flash your firmware
## How It Works

When the pcb starts, it initializes the display, gps receiver, microSD card, motion sensor, and bluetooth. The display provides an overview of the device's current status.

When recording starts, the device creates a csv file on the microsd card. It periodically saves available gps information and motion sensor readings to that file.

Bluetooth allows commands to be sent to the device and recorded logs to be requested and since the data is stored locally, recording does not require an active bluetooth connection.
## Features

- GPS Tracking: Collects location, speed, altitude, and time information from the GPS receiver.
- offline logging: Saves gps and sensor readings to a microsd card in csv format without needing a phone or Bluetooth connection.
- OLED display: shows gps status, speed, battery voltage, and recording status.
- Motion sensing: Uses the bmi270 accelerometer and gyroscope to collect movement data.
- Bluetooth connectivity: allows a compatible phone or computer to communicate with the device and request recorded logs.
- Physical controls: includes buttons for starting or stopping recordings and marking waypoints, and switching display pages.
- Status indicators: Uses an led and buzzer to provide basic feedback during operation.
# GPS Logger — Bill of Materials

| Name | Purpose | Quantity | Total Cost (USD) | Link | Distributor |
|---|---|---:|---:|---|---|
| ESP32-S3-WROOM-1-N16R8 | Main MCU (Wi-Fi/BLE) | 1 | 5.54 | [Link](https://www.lcsc.com/product-detail/C2913202.html) | LCSC |
| NEO-M9N-00B | GNSS receiver | 1 | 16.41 | [Link](https://www.lcsc.com/product-detail/C5119087.html) | LCSC |
| BQ24074RGTR | Li-ion battery charger / power path | 1 | 1.59 | [Link](https://www.lcsc.com/product-detail/C54313.html) | LCSC |
| AP2112K-3.3TRG1 | 3.3V LDO regulator | 1 | 0.13 | [Link](https://www.lcsc.com/product-detail/C51118.html) | LCSC |
| USBLC6-2SC6 | USB ESD protection | 1 | 0.13 | [Link](https://www.lcsc.com/product-detail/C7519.html) | LCSC |
| BMI270 | IMU (accelerometer/gyro) | 1 | 1.84 | [Link](https://www.lcsc.com/product-detail/C2836813.html) | LCSC |
| 0.91 inch OLED (ER-OLEDM0.91-1W-I2C) | Display | 1 | 2.80 | [Link](https://www.buydisplay.com/i2c-white-0-91-inch-oled-display-module-128x32-arduino-raspberry-pi) | BuyDisplay |
| USB-C receptacle (TYPE-C-31-M-12) | USB-C charging and data port | 1 | 0.19 | [Link](https://www.lcsc.com/product-detail/C165948.html) | LCSC |
| microSD socket (DM3AT-SF-PEJM5) | Data logging storage | 1 | 1.12 | [Link](https://www.lcsc.com/product-detail/C114218.html) | LCSC |
| JST PH 2-pin header (B2B-PH-K-S) | Battery connector | 1 | 0.03 | [Link](https://www.lcsc.com/product-detail/C131337.html) | LCSC |
| U.FL connector (U.FL-R-SMT-1) | GNSS antenna connector | 1 | 0.19 | [Link](https://www.lcsc.com/product-detail/C88373.html) | LCSC |
| Tact switch (PTS645SM43SMTR92LFS) | User buttons | 5 | 2.04 | [Link](https://www.lcsc.com/product-detail/C221880.html) | LCSC |
| Buzzer 12x9.5mm THT | Audible alerts | 1 | 1.00 | [Link](https://www.lcsc.com/category/51.html) | LCSC |
| 2N3904 | Buzzer driver transistor | 1 | 0.01 | [Link](https://www.lcsc.com/product-detail/C118538.html) | LCSC |
| 1N4148 (DO-35) | Signal/protection diode | 1 | 0.01 | [Link](https://www.lcsc.com/product-detail/C85057.html) | LCSC |
| LED 0805 (red) | Status LED | 1 | 0.01 | [Link](https://www.lcsc.com/product-detail/C84256.html) | LCSC |
| 27nH inductor 0805 | RF matching inductor | 1 | 0.09 | [Link](https://www.lcsc.com/product-detail/C251825.html) | LCSC |
| 10uF capacitor 0805 | Bulk/decoupling capacitors | 6 | 0.29 | [Link](https://www.lcsc.com/product-detail/C15850.html) | LCSC |
| 1uF capacitor 0805 | Filter capacitor | 1 | 0.01 | [Link](https://www.lcsc.com/search?q=CL21B105KBFNNNE) | LCSC |
| 100nF capacitor 0805 | IC bypass capacitors | 4 | 0.03 | [Link](https://www.lcsc.com/product-detail/C1711.html) | LCSC |
| 47pF capacitor 0805 | Filter capacitor | 1 | 0.01 | [Link](https://www.lcsc.com/search?q=0805+47pF+C0G) | LCSC |
| Resistors 0805 (10k, 5k, 1.5k, 1.8k, 100k, 2.1k, 4.7k, 1k) | Pull-ups, LED and divider resistors | 14 | 0.06 | [Link](https://www.lcsc.com/search?q=0805+1%25+resistor) | LCSC |
| PCB (bare boards) | Main PCBs | 1 | 0.40 | [Link](https://jlcpcb.com/) | JLCPCB |
| PCB assembly (PCBA fees) | SMT + through-hole assembly fees | 1 | 7.96 | [Link](https://jlcpcb.com/) | JLCPCB |

**Total estimated cost: USD 41.89**

# schematic
<img width="1616" height="846" alt="image" src="https://github.com/user-attachments/assets/bb954938-db7c-4ac1-b4a9-6bed4d3a9cf2" />
# pcb
<img width="1148" height="786" alt="image" src="https://github.com/user-attachments/assets/2d4fca5b-025a-42a9-9901-07839baa8961" />

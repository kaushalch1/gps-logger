# gps Logger

## About the Project

this is a gps device designed to record and track journeys without depending on a phone or a constant bluetooth connection.the idea behind this project is to make it easier to collect travel and movement data while hiking or cycling or exploring new places.

the device uses an esp-s3 as its main controller, along with a gps receiver and an oled display, a motion sensor, and a microsd card for storing data. it records information locally so that it can be accessed later, even without an internet connection.


## Tools used

kicad ,github

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
# schematic
<img width="1616" height="846" alt="image" src="https://github.com/user-attachments/assets/bb954938-db7c-4ac1-b4a9-6bed4d3a9cf2" />
# pcb
<img width="1148" height="786" alt="image" src="https://github.com/user-attachments/assets/2d4fca5b-025a-42a9-9901-07839baa8961" />

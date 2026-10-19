# date:10/10
# time spent:1.5hr
## description:
I started searching for projects in hardware and i was thinking that a project would be good if we use it for travelling and specifically for hiking or some adventure the basic idea was that it would log the basic data about the hiking like it saves the gps data,how many km we had been walking,motion sensing this all works with the recharaable battery and displays on a oled display
Components:
MCU	ESP32-S3-WROOM-1
GPS	u-blox NEO-M9N
IMU	BMI270 
Display	2.4-inch
Storage	microSD card
Power	USB-C 
RTC	DS3231 
Controls	5 buttons + reset	Menu navigation
## images:
<img width="1291" height="750" alt="image" src="https://github.com/user-attachments/assets/bc662008-1252-4330-823d-fdeb9c35ea4a" />

-------
# date:11/10
# time spent:1hr
## description:
i started with adding the micro controllert first by adding the esp-s3, which is going to be the main controller of the device. i also worked on the basic power connections and added a capacitor to help keep the power stable. After that, I added the reset and boot buttons so i can restart the essp32 and put it into programming mode when needed. This was mainly about getting the basic setup ready before moving on to the more interesting parts like the GPS module, OLED display, battery charging circuit for offline logging.
## images:
<img width="1577" height="847" alt="image" src="https://github.com/user-attachments/assets/106453bd-bba4-438d-a666-33e89f4adb29" />

-------
# date:11/10
# time spent:1.75hr
## description:
in this part i had started with the power block that by adding the power usb c so that it can charge and planned the two 5.1kΩ resistors for the cc pins so the device can draw power correctly from the source. i also planned the usb data connections for programming the ESP32 and included USB protection in the design. for battery charging I chose the BQ24074 charger because it supports powering the device while charging the battery. Finally, I worked on the plan for a 3.3v regulator to supply the ESP32 and other components along with battery monitoring and charging status indicators.
## images:
<img width="691" height="682" alt="image" src="https://github.com/user-attachments/assets/4a8c02f4-9e5d-4ef3-81f3-45f34db4a686" />
<img width="562" height="746" alt="image" src="https://github.com/user-attachments/assets/ab1efde3-1042-4baa-b76f-6df63ba72c10" />
<img width="1267" height="797" alt="image" src="https://github.com/user-attachments/assets/734f006f-db60-4c49-9db5-88c6fd2af45f" />


-------
# date:11/10
# time spent:1hr
## description:
next i started studing about different types of antenas and started building the NEO-M9N receiver, which will help the device collect information such as location, speed, altitude which would be great for the project. then i worked on its power and ground connections and planned the connections between the gps module and the esp controller so they can communicate with each other. i also looked and verified at the antenna connection and the requirements for receiving signals properly and more accurately. this block is important because the gps data will be used to track journeys and save location info to the microsd card.
## images:
<img width="1245" height="747" alt="image" src="https://github.com/user-attachments/assets/b9b8fecd-7796-4434-96ea-14e203b6bdc2" />
<img width="582" height="675" alt="image" src="https://github.com/user-attachments/assets/9be959b2-1251-46ed-9094-fee1fdedd3be" />

-------
# date:11/10
# time spent:0.75hr
## description:
next i started searching for the oled displays so that it can display the out put,planned to use a 0.96 inch SSD1306 oled screen to show information such as gps coordinates, speed, battery level.and then i searched for motion sensing, i chose the BMI270 accelerometer and gyroscope, which will help record movement data along with the GPS information.both devices are planned to share the same i2c bus to keep the circuit simpler. this will display information and collect motion data, which can later be saved to the microSD card.
## images:
<img width="1117" height="707" alt="image" src="https://github.com/user-attachments/assets/9a45e79a-8463-49e9-86c9-d7990be3c1c5" />
<img width="1108" height="720" alt="image" src="https://github.com/user-attachments/assets/aa2b0afb-ee9d-4591-99ba-750cee6804cd" />

-------
# date:12/10
# time spent:1.25hr
## description:
in this block i started learning how a sd card slot works and added one micro sd slot and using spi communication so the esp s3 microcontroller can save gps and sensor data directly to the card, even without a phone or bluetooth connection.i also added three buttons for controlling recording , marking waypointsand going through the software. i also planned a buzzer for alerts and a status led to indicate when the device is recording or needs attention. the next part is running the drc and checking the errors
## images:
<img width="1172" height="737" alt="image" src="https://github.com/user-attachments/assets/29552daa-b718-4b8f-87d6-90b210c5d7dc" />
<img width="745" height="593" alt="image" src="https://github.com/user-attachments/assets/cc56babf-b915-40c4-bf1e-31065c247547" />
<img width="975" height="741" alt="image" src="https://github.com/user-attachments/assets/3ebbb79c-f305-4a34-a558-3d509a508cb4" />


-------
# date:12/10
# time spent:0.75hr
## description:
I started verifying my circuit one by one and then i started the electric rule checker and then started checking there was 55 errors and many other were warning , i started checking each one by one many were regarding the unleft pins,unconneted wires and i fixed them by going through each of them.
## images:
<img width="1585" height="770" alt="image" src="https://github.com/user-attachments/assets/3ec58588-a436-4f80-b916-68913b2383ce" />
<img width="1447" height="792" alt="image" src="https://github.com/user-attachments/assets/f54f0acc-296a-4cd2-a396-d993977170cb" />
<img width="1720" height="856" alt="image" src="https://github.com/user-attachments/assets/172659f6-2bc4-461b-bbea-853ca5c3dbba" />


-------
# date:13/10
# time spent:0.75hr
## description:
I had changed and added all the footprints which weren't assigned and also fixed some footprints.
## images:
<img width="1650" height="883" alt="image" src="https://github.com/user-attachments/assets/33c4ebb1-e7b9-4410-8b16-3caa985432e8" />
<img width="1651" height="878" alt="image" src="https://github.com/user-attachments/assets/1436185e-32f1-4a6a-a703-25dc028c2af7" />



-------
# date:14/10
# time spent:1hr
## description:
I had arranged all the grouped footprints and made them arrange in a proper layout so that everything works perfectly fine
## images:
<img width="1568" height="807" alt="image" src="https://github.com/user-attachments/assets/f821abb3-9341-40a2-970c-1e6a8a07755f" />

-------
# date:17/10
# time spent:2.5hr
## description:
I had started routing all the wires and then i had filled the ground planes and then i had fixed all the drc errors and comleted the pcb part.
## images:
<img width="878" height="767" alt="image" src="https://github.com/user-attachments/assets/f6d46a4c-2348-4dfc-87d0-4faa4f74cfb7" />
<img width="1268" height="792" alt="image" src="https://github.com/user-attachments/assets/4856f302-4d9c-477e-93a6-caa56f7e33c3" />
<img width="1917" height="828" alt="image" src="https://github.com/user-attachments/assets/acabdd9b-04ef-48a1-9100-ec2397185b54" />
<img width="816" height="780" alt="image" src="https://github.com/user-attachments/assets/bc327b21-df82-4e2d-b784-731d7a4cf5ac" />


-------
# date:17/10
# time spent:1.5hr
## description:
i had started learning how to build firmware and then learned the basics of it and then tried to build the gps logger in the wokwi online simulator and then with the help of ai i tried learning and building the firmware.
## images:
<img width="1295" height="827" alt="image" src="https://github.com/user-attachments/assets/25aca0d7-320d-4d70-9bc9-7c3e1a148e38" />
<img width="467" height="248" alt="image" src="https://github.com/user-attachments/assets/19acdae3-8baf-4979-b374-0e8efc4db270" />



-------

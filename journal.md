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

# Fan-Controller-System
Temperature controlled fan system

## system components :
1. Atmega 32
2. LCD
3. LM35 Temperature sensor
4. DC Motor
5. L293 driver

## Project Description:
1. Temperature-controlled fan using ATmega32 microcontroller, in which the fan is automatically turned ON or OFF
   according to the temperature.
2. the LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it.
   This analog signal is given to the ADC, which converts the analog values to digital values.
3. The microcontroller will continuously monitor the temperature and based on the temperature value,
   the microcontroller will drive the fan like that: 
   a.	If the temperature is less than 30C turn off the fan. 
   b.	If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed. 
   c.	If the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed. 
   d.	If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed.
   e.	If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.
4. Controling the DC-Motor speed using PWM signal generated from Timer0 .

## project Design :
- The project is designed and implemented based on the layered architecture model as follows :
![image](https://github.com/Mo3aadel/Fan-Controller-System/assets/140068401/7ecf36c0-9e55-46c2-8658-ee9349ef74bd)

## System States :
a. 
![Screenshot (98)](https://github.com/Mo3aadel/Fan-Controller-System/assets/140068401/ffbd1bfd-3c0b-4d6d-a765-14094f618a2b)

b.
![Screenshot (99)](https://github.com/Mo3aadel/Fan-Controller-System/assets/140068401/c4a54de6-18f1-46e8-901c-2ed8a1508552)

c.
![Screenshot (100)](https://github.com/Mo3aadel/Fan-Controller-System/assets/140068401/6368e39a-453f-4e79-9877-75ef1ea739b6)

d.
![Screenshot (101)](https://github.com/Mo3aadel/Fan-Controller-System/assets/140068401/e5de6c01-4676-4ffc-a4a6-aa56977c88be)

e.
![Screenshot (103)](https://github.com/Mo3aadel/Fan-Controller-System/assets/140068401/12ea2a4c-e7d9-44a0-9cf0-575a592c06b4)

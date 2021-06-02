# Thermometer M5Stack Atom
Group 2

## Description

This program provides the user with an automated thermometer using the  M5 Stack Atom Matrix device. The development of this board is based around the ESP32 PICO processor, has a programmable button, 5x5 RGB LED matrix panel(WS2812C), Built-in Infra-red LED transmitter, Built-in MPU6886 Inertial Sensor, Extendable Pins & Holes, and can be programmed through the Arduino Environment. 

Demonstration video: https://youtu.be/IbYTTPb3BjE

To activate the screen: 
- Tap on the side
- Press the screen

The atom is programmed to be activated in either way. Once the screen is activated the selection of modes is possible

The thermometer has 5 different modes, represented on the screen of the atom by the number itself:

1. Show current temperature in degrees Celsius
2. Show average of last 24 hours of temperature in degrees Celsius
3. Color scale of temperature range followed by the current temperature 
4. Graph of the last 5 readings of temperature
5. Show current temperature in degrees Fahrenheit


Changing Modes:

In order to change across modes the atom needs to be tilted to the right or to the left. 
- Tilting to the right will go to the next mode
- Tilting to the left will return to the previous one

Selecting Mode:

In order to selct the desired mode, the user should press the screen when the number of this mode is on the display. 


Additional Instructions:

The atom must be held with the screen facing upwards for it to work
The user should wait until the display of temperature is finished (after the units) to switch modes. 

## Library Dependencie

- M5Atom 

## Color Scale 

To display the temperature as a color scale we used the coolest and hottest temperature records in Abu Dhabi. The ranges of colors with respect to temperature readings are the following:

BLUE below 60 F
WHITE 60 - 70 F
GREEN 70 - 80 F
YELLOW 80 - 90 F
ORANGE 90 - 100 F
RED  above 100 F


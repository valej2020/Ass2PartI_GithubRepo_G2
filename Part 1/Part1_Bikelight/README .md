# Bikelight_G2
 Group 2 - Vale Juarez, Flavia Trotolo , Hamad Al Shamsi, Sayed Ali Madani
 
# Description 
 This program provides the user with an automatic brake light for the M5 Stack Atom Matrix device. 
The development of this board is based around the ESP32 PICO processor, has a programmable button, 5x5 RGB LED matrix panel(WS2812C), Built-in Infra-red LED transmitter
 Built-in MPU6886 Inertial Sensor, Extendable Pins & Holes, and can be programmed through the Arduino Environment. 
The program assumes that the power is already available and that the device is mounted with the USB-C plug mounted facing the ground and the LED Matrix facing towards the
rear/front of the bike.

Demonstration video: https://youtu.be/IbYTTPb3BjE

The atom has the five different modes:
1.  OFF: All LEDs off
2. Manual Rear strobe (RED display): LEDs strobe at a predetermined interval
3. Manual Front strobe (WHITE display): LEDs strobe at a predetermined interval
4. Automatic Rear Mode Rear (RED display): LEDs are solid during a braking event. LEDs return to strobe when riding.
5. Automatic Front Mode Rear (White display): LEDs are solid during a braking event. LEDs return to strobe when riding

The user can select the preferred mode by pressing the screen.





 
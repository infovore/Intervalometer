Intervalometer
==============

This is code for an Arduino-based Intervalometer, suitable for use with any Nikon camera compatible with the ML-L3 remote control.

Compatibility
-------------

Compatible with the following Nikon cameras:

* Coolpix P7000
* D3000
* D40
* D40x
* D50
* D60
* D70
* D70s
* D80
* D90
* D7000

Requirements
------------

Written in Arduino v22. 

Libraries used:

* Debounce (http://www.arduino.cc/playground/Code/Debounce)
* NewSoftSerial (http://arduiniana.org/libraries/newsoftserial/)
* TimedAction (http://www.arduino.cc/playground/Code/TimedAction)
* nikonIrControl (http://www.vonroth.com/Arduino/NikonIrControl/)

Hardware
--------

The circuit attached consists of:

* a 16x2 LCD with a serial interface, attached to Arduino pin 1
* a quadrature encoder, with legs A and B attached to Arduino pins 2 and 4
* a push-to-make switch with pulldown resistor attached to pin 6 (in this case, a push-switch inside the quadrature encoder)
* an infrared LED on pin 13
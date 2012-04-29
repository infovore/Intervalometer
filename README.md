Intervalometer
==============

This is code for an Arduino-based Intervalometer, suitable for use with any Nikon camera compatible with the ML-L3 remote control.

Thanks to the multicameraIrControl library, it should be easily ported to other cameras supported by the library.

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

Written in Arduino 1.0. 

Libraries used:

* Bounce (http://arduino.cc/playground/Code/Bounce)
* NewSoftSerial (http://arduiniana.org/libraries/newsoftserial/)
* TimedAction (http://www.arduino.cc/playground/Code/TimedAction)
* multicameraIrControl (http://sebastian.setz.name/arduino/my-libraries/multi-camera-ir-control/)

Hardware
--------

The software has been tested on both an Arduino Uno and Arduino Pro Mini (with an ATMega328 running at 5V).

The circuit attached consists of:

* a 16x2 LCD with a serial interface, attached to Arduino pin 4
* a quadrature encoder, with legs A and B attached to Arduino pins 2 and 3
* a push-to-make switch with pulldown resistor attached to pin 10 (in this case, a push-switch inside the quadrature encoder)
* an infrared LED on pin 13

Usage
-----

The intervalometer starts off in SAFE mode. 

Rotate the encoder to choose an interval. Click the encoder in to ARM the intervalometer. The backlight will turn off, so as not to interfere with any exposure. In the bottom right of the display, a blinking "." will appear. 

Every time the remote fires, the blinking "." will become a "*", The intervalometer spends one second in this "firing" state - ie, there is a second between each interval. You may need to take this into account if you're looking for precise timings.

To return the intervalometer to SAFE mode, click and hold the encoder/switch until the backlight comes on. Release the switch, and the device will be SAFE again - and rotating the encoder will alter the interval duration.
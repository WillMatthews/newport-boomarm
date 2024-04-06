
# Boomarm for Newport Optical Power Meter Sensors

This is a very simple, quick 'n dirty mount and control system to move a Newport Optical Power Meter sensor in an arc.
I used this in my DPhil to place an optical power meter sensor in the path of a laser beam, such that I can measure the power above my detector, and then move the power meter away to do my experiment.

This repo contains the code for the NodeMCU, which is a poorly written, slap-dash piece of code that I wrote in a hurry.
To control the arm, send the angle you want the arm to move to in degrees, as a string, to the serial port.

It also contains the STL files for the 3D printed parts, which are designed to be printed in PETG (use a high infill, I used 100% for the arm and 50% for the base).

The arm is designed to grip 0.5" diameter rods, which are the standard size for Newport optical power meter sensors (and many other optical components).
You can buy them from [Thorlabs](https://www.thorlabs.com/navigation.cfm?guide_id=52).

The arm print is kind of fragile, so be careful when you're putting it together.
You may want to beef it up a bit, or use a stronger material (I used PETG, as it's all I had at the time).

## BoM

Servo: DS3218MG 20kg Digital Servo
Microcontroller: ESP8266 NodeMCU
Power Supply: 5V 2A


## Wiring

Connect the servo to the NodeMCU as follows:
- Servo VCC -> Power Supply 5V
- Servo GND -> Power Supply GND
- Servo Signal -> NodeMCU D8
- NodeMCU GND -> Power Supply GND


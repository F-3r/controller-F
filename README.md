# Controller-F

A very simple midi controller.


# Features

* 6 potentiometers which sends control change midi messages (controls 22 to 28) over 6 channels
* channel switcher and rgb led to identify the current channel.



# Build

Both, the code and the circuit, are pretty simple and straight forward.

Parts:

* 1 Arduino
* 6 10K potentiometers
* 1 RGB led, common anode (common cathode, or three separate leds would work too with some minor adjustments)
* 3 220 ohms resistors
* 1 push switch

This is how the components should be connected

<img src="https://raw.githubusercontent.com/F-3r/controller-F/master/schematics/controller-F.png">

Open up the sketch in arduino, burn the code to the board, and done :)


# Test & usage

In order to use the controller in any music software you'll need some kind of serial-to-midi bridge. 

Like:
* [ttymidi](http://www.varal.org/ttymidi/)
* [the hairless MIDI-to-Serial bridge](http://projectgus.github.io/hairless-midiserial/)

Using ttymidi, connect your arduino to the computer and run:

```bash
# you should replace /dev/ttyUSB0 with the device assgined to the arduino
ttymidi -v -s /dev/ttyUSB0 -b 9600
```

While turning the knobs you see an output like:

```bash
[f-3r@hidrogen controller-F]$ ttymidi -v -s /dev/ttyUSB0 -b 9600

Serial  0xb0 Controller change  000 022 002
Serial  0xb0 Controller change  000 022 003
Serial  0xb0 Controller change  000 022 004
Serial  0xb0 Controller change  000 022 005
Serial  0xb0 Controller change  000 022 006
Serial  0xb0 Controller change  000 022 007
Serial  0xb0 Controller change  000 022 008
Serial  0xb0 Controller change  000 022 009
Serial  0xb0 Controller change  000 022 010
Serial  0xb0 Controller change  000 022 011
Serial  0xb0 Controller change  000 022 012
Serial  0xb0 Controller change  000 022 013
Serial  0xb0 Controller change  000 022 014
Serial  0xb0 Controller change  000 023 038
Serial  0xb0 Controller change  000 023 039
Serial  0xb0 Controller change  000 023 040
Serial  0xb0 Controller change  000 023 041
Serial  0xb0 Controller change  000 023 042
Serial  0xb0 Controller change  000 023 043
Serial  0xb0 Controller change  000 023 044
Serial  0xb0 Controller change  000 023 045
Serial  0xb0 Controller change  000 023 046
Serial  0xb0 Controller change  000 023 047
Serial  0xb0 Controller change  000 024 047
Serial  0xb0 Controller change  000 024 048
Serial  0xb0 Controller change  000 024 049
Serial  0xb0 Controller change  000 024 050
Serial  0xb0 Controller change  000 024 051
Serial  0xb0 Controller change  000 024 052
Serial  0xb0 Controller change  000 024 053
Serial  0xb0 Controller change  000 025 002
Serial  0xb0 Controller change  000 025 003
Serial  0xb0 Controller change  000 025 004
Serial  0xb0 Controller change  000 025 005
Serial  0xb0 Controller change  000 003 006
Serial  0xb0 Controller change  000 023 007
Serial  0xb0 Controller change  000 023 008
Serial  0xb0 Controller change  000 023 009
Serial  0xb0 Controller change  000 023 010
#...

```

Here you can see the control change messages arriving. The 3 last numbers are: channel, control, value



# Hacking

Most of the features are controlled by the constants defined at the start of the file, like knobs count, channel count, channel indicator colors. Experiment!



# Contributions

Are always welcomed!


# References and inspiration 

* http://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-midi-output-using-an-arduino/
* http://www.tigoe.net/pcomp/code/communication/midi/
* http://hinton-instruments.co.uk/reference/midi/protocol/index.htm
* http://hinton-instruments.co.uk/reference/midi/protocol/pg02.htm
* http://forum.arduino.cc/index.php/topic,37848.0.html


# License

The MIT License (MIT)
Copyright (c) 2016  Fernando Martínez

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


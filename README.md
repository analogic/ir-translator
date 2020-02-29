Arduino IR translator
=====================
...for getting rid of secondary TV remote only for switching on/off tv. Repository contains slightly adjusted IRremote library to work with Arduino Leonardo Pro Micro.

### Current situation

![Samsung DVB-T2 STB](https://raw.githubusercontent.com/analogic/ir-translator/master/doc/stb.jpg)

Blaupunkt TV connected to Samsung DVB-T2 STB. Blaupunk remote can not control STB, Samsung STB remote can't control Blaupunkt TV even if there is red on/off button for TV. HDMI-CEC is supported in STB but not TV.

### Parts

- Arduino Leonardo Pro Micro 3.3V

#### Vishay IR receiver
- 104 capacitor - 0.1uF
- 100 ohm resistor

#### IR transmitter part
- BC548 transistor
- 22 ohm load resistor
- 10k ohm resistor (arduino pin to transistor)
- IR333C/H0/L10 IR led, 1.4 forward V, 100mA

- proto boards, headers, skill...
- heat shrink tube or printed box

### Result

IR diode legs will be adjusted after placement test

![Arduino IR translator](https://raw.githubusercontent.com/analogic/ir-translator/master/doc/r5.jpg)

![Arduino IR translator](https://raw.githubusercontent.com/analogic/ir-translator/master/doc/r4.jpg)

![Arduino IR translator](https://raw.githubusercontent.com/analogic/ir-translator/master/doc/r3.jpg)

![Arduino IR translator](https://raw.githubusercontent.com/analogic/ir-translator/master/doc/r2.jpg)

![Arduino IR translator](https://raw.githubusercontent.com/analogic/ir-translator/master/doc/r1.jpg)
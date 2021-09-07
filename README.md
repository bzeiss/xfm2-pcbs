# PCB(s) for the XFM2/XVA1 Project

This site contains some stuff I have built for the excellent FPGA XFM2/XVA FPGA DIY synths by futur3soundz/René Ceballos. You can find them here: https://www.futur3soundz.com.

I tinker with electronics, release stuff when I feel like it and I make it public when it's maybe not perfect. I'm not an electronics expert, so I may not always know what I'm doing. I learn the necessary electronics as I use it. Use at your own risk.

Be smart. Don't just trust the stuff I offer for download here. Take a look at the schematic and the PCB design beforehand and be sure not to solder the Digilent CMOD A7 and possibly also the DAC directly onto the PCB, but use sockets so that you can always dismiss the PCB if you like to do something different with those more expensive components, if someone else made a better PCB or if there is a problem on the PCB that I'm not aware of.

Feedback is always very welcome 😄

## XFM2/XVA Basic PCB

This PCB is essentially a hacked together PCB version of the original XFM2 schematic with some added pins for spdif, uart, led's and so on. It's essentially something for those of us who want something slightly nicer than a soldered perfboard and who don't want to do the wiring by hand.

**3D Render:**
![xfm2basic](https://user-images.githubusercontent.com/884834/114622434-3efde000-9cae-11eb-929d-81e718634022.jpg)

**Hand-soldered real-world example:**
![20210430_190012](https://user-images.githubusercontent.com/884834/116729936-1d0f9780-a9e8-11eb-9ad4-8c1d015c8f70.jpg)

**J2 Pins:**
![pins](https://user-images.githubusercontent.com/884834/116730545-eab26a00-a9e8-11eb-8fc8-ce8dbab01ab6.png)

**Gerber ZIP:**

https://github.com/bzeiss/xfm2-pcbs/blob/xfm2-xva1-basic-pcb-1.0/basic/gerber/xfm2-basic-v1.0.zip

**Comments:**

Please know what you are doing when you intend to use this.

The BOM is the same as the one futur3soundz, except for the optional pins that you may or may not want to add. For that, you'll need some additional 2.54mm pin headers. Please use sockets at least for the CMOD A7 and possibly also for the DAC.

## XFM2/XVA Extended PCB
This PCB is designed to offer most of the functionality that the device offers, e.g. control voltage, and it adds some additional functionality like the following:
- midi out and midi thru. Midi thru is realized through the circuit, not through the fpga as xfm2, unlike xva1, does not have a midi thru pin. Midi out and midi through are going through schmitt-trigger for a clean signal.
- LEDs for midi in, midi out, led audio, led clip. midi in and midi out leds are realized through the circuit, not through the fpga pins.
- A100 connector
- Control voltage that is regulated down to 3.3V for the Cmod A7 via the MCP6004 opamp. The A100 connector must be used in order for the control voltage pins to work.
- The board uses the H11L1 opto-coupler instead of the 4N36 of the original circuit. In some occasions, I have experienced hanging notes with the 4N36. The signal seems to be more clean through a schmitt-trigger.

![image](https://user-images.githubusercontent.com/884834/123553683-003fd800-d77d-11eb-9ecb-b90e794388ec.png)

![image](https://user-images.githubusercontent.com/884834/123553788-8e1bc300-d77d-11eb-8298-3ce04cf766a5.png)

![20210907_161729](https://user-images.githubusercontent.com/884834/132360736-ee1d62ed-7840-4739-87ed-c8730edc463d.jpg)


Schematic: https://github.com/bzeiss/xfm2-pcbs/blob/main/extended/pdf/schematic.pdf

### BOM

| Quantity | Ref                          | Value                 | Description                                                                                                                                                                      |
| -------- | ---------------------------- | --------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1        | C1                           | 10nF                  | Unpolarized ceramic capacitor                                                                                                                                                            |
| 2        | C2, C3                       | 10uF                  | unpolarized ceramic capacitor                                                                                                                                                            |
| 2        | C4, C5                       | 10uF                  | Polarized tantalum capacitor                                                                                                                                                  |
| 2        | C6, C7                       | 330p-560p             | Unpolarized ceramic capacitor                                                                                                                                                            |
| 1        | C8                           | 0.33uF                | Polarized ceramic capacitor (deviation from the schematic, this must be unpolarized!)                                                                                                                                                   |
| 1        | C9                           | 0.1uF                 | Polarized ceramic capacitor (deviation from the schematic, this must be unpolarized!)                                                                                                                                                   |
| 1        | D1                           | 1N4148                | 1N4148 Diode                                                                                                                                                                            |
| 1        | D2                           | LED_MIDI_IN           | Light emitting diode                                                                                                                                                             |
| 1        | D3                           | LED_MIDI_OUT          | Light emitting diode                                                                                                                                                             |
| 1        | D4                           | LED_AUDIO             | Light emitting diode                                                                                                                                                             |
| 1        | D5                           | LED_CLIP              | Light emitting diode                                                                                                                                                             |
| 1        | D6                           | 1N4007                | Diode                                                                                                                                                                            |
| 1        | D7                           | LED_POWER             | Light emitting diode                                                                                                                                                             |
| 6        | FB1, FB2, FB3, FB4, FB5, FB6 | Ferrite_Bead          | Ferrite bead                                                                                                                                                                     |
| 1        | J1                           | Midi In               | 5-pin DIN connector (5-pin DIN-5 stereo)                                                                                                                                         |
| 1        | J2                           | Pin Breakout          | Generic connector, double row, 02x10, counter clockwise pin numbering scheme (similar to DIP packge numbering), script generated (kicad-library-utils/schlib/autogen/connector/) |
| 1        | J3                           | Midi Out              | 5-pin DIN connector (5-pin DIN-5 stereo)                                                                                                                                         |
| 1        | J4                           | Midi Thru             | 5-pin DIN connector (5-pin DIN-5 stereo)                                                                                                                                         |
| 1        | J5                           | Conn_Coaxial          | coaxial connector (BNC, SMA, SMB, SMC, Cinch/RCA, ...)                                                                                                                           |
| 1        | J6                           | Jack-DC               | DC Barrel Jack                                                                                                                                                                   |
| 1        | J7                           | A-100_Bus_Connector   |                                                                                                                                                                                  |
| 2        | J8, J9                       | AudioJack2            | Audio Jack, 2 Poles (Mono / TS)                                                                                                                                                  |
| 1        | R1                           | 220                   | Resistor                                                                                                                                                                         |
| 1        | R2                           | 470                   | Resistor                                                                                                                                                                         |
| 2        | R3, R4                       | 33                    | Resistor                                                                                                                                                                         |
| 5        | R5, R6, R7, R8, R19          | 2k                    | Resistor                                                                                                                                                                         |
| 2        | R9, R10                      | 10                    | Resistor                                                                                                                                                                         |
| 4        | R11, R12, R13, R14           | 100k                  | Resistor                                                                                                                                                                         |
| 2        | R15, R16                     | 33k                   | Resistor                                                                                                                                                                         |
| 2        | R17, R18                     | 100                   | Resistor                                                                                                                                                                         |
| 1        | U1                           | H11L1                 | Schmitt Trigger Output Optocoupler, High Speed, DIP-6, 1.6mA turn on threshold                                                                                                   |
| 1        | U2                           | CmodA7-35T            |                                                                                                                                                                                  |
| 1        | U3                           | 24LC01                | I2C Serial EEPROM, 1Kb, DIP-8/SOIC-8/TSSOP-8/DFN-8                                                                                                                               |
| 1        | U4                           | UDA1334A              |                                                                                                                                                                                  |
| 1        | U5                           | 74HC14                | Hex inverter schmitt trigger                                                                                                                                                     |
| 1        | U6                           | LM1117-5.0            | 800mA Low-Dropout Linear Regulator, 5.0V fixed output, TO-220/TO-252/TO-263/SOT-223                                                                                              |
| 1        | U7                           | LM1117-3.3            | 800mA Low-Dropout Linear Regulator, 3.3V fixed output, TO-220/TO-252/TO-263/SOT-223                                                                                              |
| 1        | U8                           | MCP6004               | 1MHz, Low-Power Op Amp, DIP-14/SOIC-14/TSSOP-14                                                                                                                                  |
| 1        | U9                           | L79L05_SO8            | Negative 100mA -30V Linear Regulator, Fixed Output -5V, SO-8                                                                                                                     |

### Build notes
- C8 and C9 must be unpolarized ceramic capacitors (unlike shown in the schematic)

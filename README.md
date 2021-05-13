# PCB(s) for the XFM2/XVA1 Project

This site contains some stuff I have built for the excellent FPGA XFM2/XVA FPGA DIY synths by futur3soundz/René Ceballos. You can find them here: https://www.futur3soundz.com.

I tinker with this stuff when I feel like it and I make it public when it's not perfect. I'm not an electronics expert, so I may not always know what I'm doing. Use at your own risk.

Be smart. Don't just trust the stuff I offer for download here. Take a look at the schematic and the PCB design beforehand and be sure not to solder the Digilent CMOD A7 and possibly also the DAC directly onto the PCB, but use sockets so that you can always dismiss the PCB if you like to do something different with those more expensive components, if someone else made a better PCB or if there is a problem on the PCB that I'm not aware of.

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



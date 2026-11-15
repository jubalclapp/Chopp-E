# Chopp-E
MOSFET-Clipping Overdrive Guitar Pedal, derived from the Fulltone OCD
Chopp-E is a custom guitar overdrive designed for a friend. The process began with the well known OCD circuit as a starting point; each stage was then analyzed by hand and verified in LTspice, and the problems encountered along the way were remedied. The mechanical footswitch was replaced by a microcontroller relay bypass.
<p align="center"><img src="hardware/overdrive_pedal.png" width="640"></p>

## Specifications
| Spec | Value |
| ---- | ----- |
| Controls| Drive (A1M), Tone (B10K), Volume (A100K), Hi/Low toggle |
| Bypass| Relay true bypass, soft touch footswitch, output muting during switching |
| Clipping| Asymmetric MOSFET clipping (2N7000 / body diode) |
| Gain| 17.4 dB to 45.5dB, input to clipper |
| Power| 9 V DC, ~7.4mA |
| PCB| two layer, solid ground plane, SMD fixed parts, socketed tone shaping parts |
## Changes from reference
1. Input buffer. Removed JFET's drain resistor, ensuring it remains saturated across the full $I_{DSS}$ range listed on the datasheet
2. Output buffer. Converted the collector output stage to an emtiier-follower, tripling headroom (0.9$\pm$V to 2.6$\pm$) and cutting input impedence from 10k $\omega$ to 230 $\omega$
3. Relay bypass. An ATtiny85 drives a latching relay and mutes the output while switching.
## Repo Layout
hardware/     KiCad project files
firmware/     ATtiny85 bypass coltroller (PlatformIO)
***
*Jubal Clapp | Electrical Engineering @ Queen's University | Fall 2026*
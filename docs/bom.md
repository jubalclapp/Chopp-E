# Bill of Materials
A master list of all non-smd components to build the Chopp-E Overdrive Guitar Footpedal. It is assumed that all smd components will be placed by the PCB manufacturer.<br>
## Assembly recommendations
The following are some assembly recommendations, aligning with the intended design of the pedal:<br>
- Connect potentiometers on the external panel with knobs for ease-of-use, use 24 AWG wire to connect to the PCB<br>
- Purchase a USBasp ISP programmer and flash the ATtiny85 with the .hex file found in [Firmware](/releases/chopp-e_v1.0.hex)<br>
## BOM table
| Ref | Component Value | Package | Qty |
| --- | --------------- | ------- | --- |
| R10 | 39k$\Omega$ | Axial, 7.62mm | 1 |
| R11 | 22k$\Omega$ | Axial, 7.62mm | 1 |
| R12 | 33k$\Omega$ | Axial, 7.62mm | 1 |
| R21 | 2.2k$\Omega$ | Axial, 7.62mm | 1 |
| C3 | 220pF, C0G ceramic | Radial, 5mm | 1 |
| C6 | 47nF, film | Radial, 5mm | 1 |
| C10 | 220pF, C0G ceramic  | Radial, 5mm | 1 |
| C11 | 100nF, film | Radial, 5mm | 1 |
| Q1 | 2N5457 N-Channel JFET | TO-92 | 1 |
| Q2,Q3 | 2N7000 N-Channel MOSFET | TO-92 | 2 |
| D2 | 1N34A germanium diode | DO-35 | 1 |
| U2 | TL072CP dual op-amp | DIP-8 | 1 |
| U3| L78L05ACZ 5V regulator | TO-92 | 1 |
| U4 | ATtiny85 microcontroller | DIP-8 | 1 |
| U5 | TLP222A photo-MOSFET relay | DIP-4 | 1 |
| Q4 | 2N5088 NPN BJT | TO-92 | 1 |
| Q5, Q6 | 2N7000 N-Channel MOSFET | TO-92 | 2 |
| D1, D5, D6 | 1N4148 signal diode | DO-35 | 3 |
| D4 | 1N5817 Schottky diode | DO-41 | 1 |
| D3 | LED, 3mm | THT | 1 |
| K1 | Omron G6SK-2 DC5 latching relay | THT | 1 |
| C9, C15 | 10$\mu$F, 25V electrolytic | Radial | 2 |
| C12 | 220$\mu$F, 25V electrolytic | Radial | 1 |
| C13 | 47$\mu$F, 25V electrolytic | Radial | 1 |
| J1, J2 | 1/4 inch mono jack enclosure mount | Panel | 2 |
| J4 | 2.1 mm DC jack | Panel | 1 |
| RV1 | B10K potentiometer, 16mm | Panel | 1 |
| RV2 | A100K potentiometer, 16mm | Panel | 1 |
| RV3 | A1M potentiometer, 16mm | Panel | 1 |
| SW1 | SPDT mini toggle | Panel | 1 |
| SW2 | Momentary soft-touch footswitch | Panel | 1 |
| --- | DIP-8 IC Socket, U2&U4 | Sockets | 2 |
| --- | Machined-pin socket strip, 1X40 | Socket | 1 |
| --- | USBasp ISP programmer | Tool | 1 |

*Jubal Clapp | Electrical Engineering @ Queen's University | Fall 2026*
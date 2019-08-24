---
layout: page
title: Audio
nav_order: 2
---

## Audio Experiments
### **SETUP**

| Nano 33 BLE | Nano 33 BLE Sense |
| :---: | :---: |
| ![Nano 33 BLE](./nanoble_new_clean.jpg) | ![Nano 33 BLE Sense](./nanoble_sense_labled.jpg) |

To save _setup costs_ often boards that are efectively the same have exactly the same schematics and layout even though one may lack certain ICs. That is exactly the case with Nano 33 BLE and Nano 33 BLE Sense. _That's why you have unpopulated places on the Nano 33 BLE_!  
Since I have Nano 33 BLE, all I need to do is get the relevant ICs and solder them at their respective places and I have something in between Nano 33 BLE and Nano 33 BLE Sense !  
I am especially interested in Audio because of the immense potential with audio based applications with the DSP core of the ARM Cortex M4 especially the Artificial Intelligence and Machine Learning capabilities like running Tensorflow Lite !  
I got STMicroelectronics to send me some free samples of their MP34DT05 microphone to solder on my board.
This is what I ended up with -  

| ![My Nano BLE](./nanoble_microphone.jpg) | ![Original Nano BLE](./nanoble_new_clean.jpg) |

### **Testing the Microphone**
The Microphone outputs audio in PDM format so we can use the Example Sketch that comes inbuilt **PDMSerialPlotter** from `File->Examples->PDM->PDMSerialPlotter`.
I used the _ToneGenerator_ android app to generate various waves at varying frequencies to check the output waveforms on the plotter.  
Outputs - 
![plot1](./plot1.png)
![plot2](./plot2.png)
![plot3](./plot3.png)

#### More custom Audio Experiments
- Integrating Serial with Processing to perform interesting transforms.
- Getting the ArduinoSound Library to work - FFTs and other things.
- Changing the inbuilt parameters of the PDM Library as right now changing anything doesn't work at all.
---
layout: default
title: Home
nav_order: 1
---

# All things Arduino Nano 33 Bluetooth
{: .fs-9 }

I was able to get the Nano 33 BLE in July as I had preordered it so I got down to play with it.
{: .fs-6 .fw-300 }

[Purchase](https://store.arduino.cc/usa/nano-33-ble){: .btn .btn-primary .fs-5 .mb-4 .mb-md-0 .mr-2 } [ArduinoBLE on GitHub](https://github.com/arduino-libraries/ArduinoBLE){: .btn .fs-5 .mb-4 .mb-md-0 .mr-2} [Reference](https://www.arduino.cc/en/Reference/ArduinoBLE){: .btn .fs-5 .mb-4 .mb-md-0 .mr-2}

---

## Important Differences
The board as displayed on the Website is different than what you actually get. There is actually a RGB LED on board that you don't see in the official image and the official image has an IC that isn't there in the real board. Take a look -  

--- | ---
:-------------------------:|:-------------------------:
![Offical Image](./nanoble_old.jpg)  |  ![Real Board](./nanoble_new.jpg)

---

## First things first
The pins that have been brought out as headers can be addressed just like you'd for say Uno and you can see them in the Tech Specs. It's the pins that haven't been brought out and you may need to control like the RGB pins or the 2 LEDs that might need your attention.  

The [official documents](https://store.arduino.cc/usa/nano-33-ble) are not yet upto speed with Board Definitions. I made the mistake of actually opening the schematics and layout in Autocad Eagle to find out the PIN definitions. But that's incorrect as they may or may not be the same as the internal pin definitions. I even ended up asking this on the [Forum](https://forum.arduino.cc/index.php?topic=630665.0). You can read it to find out how I found the pins _experimentally_ for the RGB LED.  

The answer there led me to the repository where the actual **board pin definitions** are written. So this is what you must use to declare pins in your sketches-  

| LED | PIN |
| :---: | :---: |
| PIN_LED | 13u |
| RGB LED RED | 22u |
| RGB LED GREEN | 23u |
| RGB LED BLUE | 24u |
| LED_PWR | 25u |

**Note:** _The 2 general LEDs are as usual, when the digital pin they are attached to goes high, they glow. But the RGB LED is wired in the opposite way i.e it's connected to the power rail so you need to drive the pins they are connected with to LOW to turn them ON._

Following is the usual ones(header pins) as mentioned in the Tech Specs.

```cpp
// Analog pins
// -----------
#define PIN_A0 (14u)
#define PIN_A1 (15u)
#define PIN_A2 (16u)
#define PIN_A3 (17u)
#define PIN_A4 (18u)
#define PIN_A5 (19u)
#define PIN_A6 (20u)
#define PIN_A7 (21u)

// Serial (EDBG)
#define PIN_SERIAL_RX (1ul)
#define PIN_SERIAL_TX (0ul)

// SPI
#define PIN_SPI_MISO  (12u)
#define PIN_SPI_MOSI  (11u)
#define PIN_SPI_SCK   (13u)
#define PIN_SPI_SS    (10u)

// Wire
#define PIN_WIRE_SDA        (18u)
#define PIN_WIRE_SCL        (19u)

#define PIN_WIRE_SDA1       (30u)
#define PIN_WIRE_SCL1       (31u)

#define PIN_ENABLE_SENSORS_3V3     (32u)
#define PIN_ENABLE_I2C_PULLUP      (33u)

#define PIN_INT_APDS (26u)

// PDM Interfaces
// ---------------
#define PIN_PDM_PWR	 (27)
#define PIN_PDM_CLK	 (28)
#define PIN_PDM_DIN	 (29)
```
---

### More experiments to follow...

### BLE Experiments

### Audio Experiments
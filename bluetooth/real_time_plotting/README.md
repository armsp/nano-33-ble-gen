1. Open `index.html` in Chrome
2. Upload Sketch to Arduino Nano 33 BLE
3. Connect by clicking on the `Connect` button
4. Watch the real time graph update its values.

NOTE
----
<strike>The p5.ble.js library has some issues handling the float values. Even though we are passing string here, I would recommend you to use the local p5.ble.js and p5.js libraries till the Fix is merged to the library.</strike>  
Fix has been issued. Changes have been made to use the appropriate CDN.

TODO
----
- [ ] Add **WebUSB** code too so that it automatically takes you to the webpage where the whole demo works.
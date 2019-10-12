---
layout: page
title: Linux Troubleshooting
nav_order: 100
---
My experience with Arduino on Ubuntu was excruciatingly painful. On Windows everything seems to just work :man_shrugging: . After some digging up I tried the following and it actually helped a lot.   
Hopefully one of them will work for you -

1. Turn off all powersaving like `powertop` and `tlp`.
2. Turn off bluetooth connections like speakers, headphones.
3. Double-click the **reset** button in quick succession.
4. ```sudo apt-get purge modemmanager```
5. ```sudo chmod a+rw /dev/ttyACM0```
6.  ```
    sudo usermod -a -G tty <username> OR sudo usermod -a -G tty $USER
    sudo usermod -a -G dialout <username> OR sudo usermod -a -G dialout $USER
    ```

6. ```sudo chmod a+rw /dev/ttyUSB0```

7. ```sudo chown username /dev/ttyUSB0```

8. ```sudo chown username  /dev/ttyACM0```

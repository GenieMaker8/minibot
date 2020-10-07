# Mini Bot Droid
License Agreement: Cannot use Mini Bot files and its source codes for anything that might be considered commercial use.


Mini Bot Droid Assembly
========================
Folloing our assembly video in our youtube channcel 

https://www.youtube.com/watch?v=-MLlWDRjhKo

Mini Bot Droid Self-Driving in action 
=====================================
https://www.youtube.com/watch?v=s8Ky_U1seNI

Mini Bot Droid Back Away mode  
=============================
https://www.youtube.com/watch?v=Pbk3FJg0sq4


Re-install Mini Bot Droid program: 
==================================
If Mini Bot was reloaded with other example programs from Arduino, the origin Mini Bot Droid program will be erased. You can re-install the binary by following steps.   

1. Download the hex file bot33_mini_bot.ino.hex into your folder C:\Users\<username>\Downloads
2. Find the port name by looking up at the Arduino IDE. 
     - Use USB cable to connect Arduino Board to your PC
     - click on the IDE top window menu "Tools" and click the "port" to see Arduino Board port name
     - Replace -PCOM3 to your port name such as following port name "COM7" in following command
        example: -PCOM7

3. Following commands use " " due to extra space between "Program Files (x86)"
 
4. Run this command at the cmd window to load the Mini Bot program into Arduino board with proper port name e.g -PCOM3

“C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avrdude” “-CC:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf“ -v -patmega328p -carduino -PCOM3 -b115200 -D -Uflash:w:C:\Users\<username>\Downloads/bot33_mini_bot.ino.hex:i

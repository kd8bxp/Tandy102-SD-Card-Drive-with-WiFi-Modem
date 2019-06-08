# Tandy 102 WiFi SD Card

This could not have been made without the following projects:  
 MyTeSed: T100 SD Card Reader for the Arduino Nano and SD Card Reader. By David  
Stephenson 10-11-2017.  
https://www.zx81keyboardadventure.com/2017/08/model-100-micro-sd-card-reader-mytesed.html  
https://youtu.be/7AtsHzl9WMc  
This project "emulates" a PDD - I use emulate loosely. It does let you load and save programs to/from the Tandy 102. It saves the programs to the SD card.  

The next project is the C64-WiFiModem project that was based on serveral other projects.  
The version I used can be found here:  https://github.com/DrZingo/c64-wifimodem  
   C64-WiFiModem - (c) 2017 my2bits <markus at borgelin.org>  
See the credit.h file for more information about this project.  
The basics of it, it gives the ability of vintage machines to connect to the web,  
and is really good for telneting to online BBS systems.  
AT? for help.  

These two projects were ported over to the ESP32, which wasn't that hard to do, a few changes to the base code were needed.  
One thing that stopped working is the ability to telnet into the vintage machine (so for now, you can't run that BBS on your Tandy 102).  

The final project that made all this come together is FTP Server based on FTPServerSample & esp8266FTPServer by nailbuster Oct 2017
https://github.com/nailbuster/esp8266FTPServer
Modified by robo8080 for SD card use 2017 https://github.com/robo8080/ESP32_FTPServer_SD  

The only thing I did was to add some feedback displayed on the OLED, otherwise that project already worked on the ESP32  
 
## Things To Do

After I got all the code working, I just merged the 3 base codes together with a menu system that I wrote, because of this:  
There is some redundant code, and future versions I want to clean it up as much as  
I can.  
Telnet Server doesn't work, I'd like to figure out how to get that working.  
And maybe add code in all the bases to switch from one mode to the next easy. (Maybe)  
The SD card reader needs to have the leading "/" included with file names.  
I'd like to have software check for this an add it if needed.  
Currently, you need it otherwise it doesn't work - there is no error printed so you don't know it doesn't work.  
Interestingly enought you don't need the leading "/" when using FTP, but you do need a good FTP client, at least I did.  

## Hardware Used

1) TTGO T-eight board - this board has an ESP32, on board SD card reader/writer, 3 switch/button toggle, OLED, and lipo charger (I'm not using a battery).  
2) MAX232 board, the board I am using has a 9pin female connector, and only has RX/TX broken out. 5v and Ground  
3) 9 pin to 25 pin serial adaptor for the Tandy, and maybe/probably a 9 pin serial gender changer.  
4) (Optional) 3D printed case and stand.  

Hookup is fairly easy and straight forward, connect the Max232 VCC to 5v pin, GND to GND, TX to TX, and RX to RX, load the sketch on the board, and test.  
IF it doesn't work, try reversing the TX and RX pins (in other words, connect TX to RX, and RX to TX).  


## Usage

My Tandy 102 didn't like an speed but 300 baud, I know slow. So you need to have your com port set for 300 baud. (38N1D works)  
For the SD card drive, in the terminal type "help" without the quotes. You'll get a
small amount of "help" - It's not very good, but might be enough to give you some help.  

For the C64-WiFiModem you can use "AT?" in command mode, and you'll get some help.  

You need a good FTP Client when using the FTP mode.  
(You don't need to remove the SD card, and can copy and move files on the SD card over FTP) - It's nice!   

To get back to the menu, use the center button.  The ESP32 will reset and you'll get the menu again.  

## Demo Video

coming soon....  

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Support Me

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  
https://www.paypal.me/KD8BXP  

## Other Projects

https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  


## Credits

Copyright (c) 2019 LeRoy Miller

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>

# pisorting
This is working off of the system found at this repo:
https://github.com/s-matyukevich/raspberry-pi-os

That repo has a wonderful description of everything that is going on in this "kernel"

As it currently is, this system can execute C code without the standard library or any memory management functions. 
It also uses a limited ```printf```, so to print floats or more will require a replacement library!

## To Compile
Just run ```make``` from the root folder. 
This will output ```kernel8.img```, which is the kernel that will get copied to the Pi

Be aware that with the current compiler flags set that this system will not support floating point operations, the flag will need to be removed

## To Run on the Pi
The Pi needs to be formatted correctly to run
 - Write an image of Raspbian to an SD Card
    - This will set up the SD Card properly
 - Test that the Pi boots into Raspbian
    - While in the Raspberry is running, go into the settings and enable Serial Communication in the ```raspi-config```
  - After enabling the serial communication, the SD Card can be formatted for the custom kernel
    - Remove all ```kernel*.img``` files from the SD Card
    - Copy the compiled ```kernel8.img``` to the SD Card
    - The File ```config.txt``` needs to be replaced with the following:
```
kernel_old=1
disable_commandline_tags=1
```
It should boot now
For more information please see the guide: https://github.com/s-matyukevich/raspberry-pi-os/blob/master/docs/lesson01/rpi-os.md

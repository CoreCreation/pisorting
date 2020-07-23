# pisorting
## To run
* Run make in root folder
* Copy kernel8.img to SD card of Raspbian written SDcard
 - Raspbian needs to have serial communication enabled in the config before the kernel is overwritten 
* Remove all the other kernel files

```
kernel_old=1
disable_commandline_tags=1
```
This is working off of the system found at this repo:
https://github.com/s-matyukevich/raspberry-pi-os

That repo has a wonderful description of everything that is going on in this "kernel"

As it currently is, this system can execute C code without the standard library or any memory management functions. 
It also uses a limited ```printf```, so to print floats or more will require a replacement library!

## To Compile
Just run make from the root folder
Be aware that with the current compiler flags set that this system will not support floating point operations, the flag will need to be removed


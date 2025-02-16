# CHIP8_Emulator
This is a CHIP8 Emulator written in C. It uses GTK to make a desktop application, and uses modern OpenGL to implement the CHIP8 display.


## Setup
#### Note: This was developed on Ubuntu. So long as you can install gtk4, etc. you should be able to build from src for your platform. The instructions I provide will be using the `apt` package manager for examples.


### Prequisites
#### GTK4
On a debian linux distro you can install with apt
```
sudo apt-get install libgtk-4-1 libgtk-4-1-bin libgtk-4-1-dev
```
This provides GTK4 and the cflags via pkg-config which gets used in the Makefile.


#### glu
On Ubuntu 24.04 (at time of writing) it seems that the the `glu.h` file is missing from the default OpenGL install, so I had to install this to have /usr/include/GL/glu.h present.
```
sudo apt-get install libglu1-mesa libglu1-mesa-dev
```
I found that package using the `apt-file` package to search for  `glu.h`.


#### cpplint
Note that this is written in C but most of the styling guidelines are still applicatble. Anything that follows the [Google Style Guide](https://google.github.io/styleguide/cppguide.html) will be consistent with what is in this project.
```
sudo apt-get install cpplint
```


### Build
```
make
```


### Run
```
./main
```


### Lint
```
cpplint --recursive src include
```
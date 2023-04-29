# Space-Invaders

## General information

This program is a simple shooter-game that I did as a free-time project. 

## Requirements for using the program

To start this game, you will need the SDL 2 -library. Specifically, you must be able to include the following files: "SDL.h", "SDL_ttf.h" and "SDL_image.h". These files should be located in /usr/include/SDL2. If they are located somewhere else in your machine, you must modify the makefile correspondingly. This program has been tested only in Linux-environment.

## How to start the program

To compile the program, run the following commands in the top-level folder:

autoreconf -i
./configure
make

Now you can start the game by running "./space_invaders".

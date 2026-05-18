# raylib_pong

Pong game in C using raylib

![alt text](https://github.com/TheGreatYagi/raylib_pong/blob/main/screenshot/TitleScreen.png "Pong!")

## Build instructions
1. First download raylib and build it according to your platform:
```
$git clone https://github.com/raysan5/raylib.git

Follow instructions here:
https://github.com/raysan5/raylib/tree/master#build-and-installation
```
2. Once built, configure your path to point to build directory (typically found in /path/to/dowloaded/raylib/raylib)
```
export RAYLIB_PATH=/path/to/dowloaded/raylib/raylib
```
3. Finally run `make` in raylib_pong directory to build game. Currently the make file is optimized for Apple Silicon. Will eventually update to include Windows and Linux


## Features

Currenlty only supports 2 levels, but should be easy to add more.


### Screenshots

![alt text](https://github.com/TheGreatYagi/raylib_pong/blob/main/screenshot/GamePlay.png "Game Play")

![alt text](https://github.com/TheGreatYagi/raylib_pong/blob/main/screenshot/Level1Win.png "Level Win" )

![alt text](https://github.com/TheGreatYagi/raylib_pong/blob/main/screenshot/WinGame.png "Game Win" )

![alt text](https://github.com/TheGreatYagi/raylib_pong/blob/main/screenshot/LoseGame.png "Level Lose" )
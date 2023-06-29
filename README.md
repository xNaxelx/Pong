# Pong

Game on SDL2 graphic library
![image](https://github.com/xNaxelx/Pong/assets/46362288/707862e3-774c-4976-b412-87b64043c4a4)


## Control

 - `↑` - Move stick to up
 - `↓` - Move stick to down

# Project compilation
## Requirements
 - [CMake](https://cmake.org/download/)
 - [vcpkg](https://github.com/Microsoft/vcpkg/#quick-start-windows)
## Library installation

Execute commands in vcpkg:
 - `vcpkg install sdl2:x64-windows`
 - `vcpkg install sdl2-image:x64-windows`
 - `vcpkg install sdl2-mixer:x64-windows`
 - `vcpkg install sdl2-ttf:x64-windows`
 - `vcpkg integrate install`

## Generate project files

1. In CMakeLists.txt on the first line change the path to vcpkg
2. Open cmake-gui.exe
3. Specify the path to the folder with the project and the folder where the assembly will be made
 ![image](https://github.com/xNaxelx/Pong/assets/46362288/d5978519-82f0-4484-9588-1a7bc59413df)
4. Press `Configure` and after the end `Generate`

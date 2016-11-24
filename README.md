# googlemocktemplate

This is an example template project using GoogleMock and GoogleTest in combination with CMake
It contains a simple main file which will multiplicate 2 numbers and a test unit which will test the functionality.
It also contains a .gitlab-ci.yml file, if you are using Gitlab CI.
I am nether an expert with CMake nor GoogleMock, so this repo might not be the easiest way to combine those tools, but it works.
Feel free to propose better solutions to improve this code example.

## Tested with

- Windows 7 (initial commit)
- Ubuntu 16.04.1 LTS (initial commit)

## Prerequisites

- Use a 64 Bit Operating System Windows or Linux
- Install CMake
- a GCC compiler for Linux, Visual Studio 2015 for Windows. 
- Git Bash (for executing the bash commands )
- Get git clone over ssh to work to download googletest submodule

## Build Setup

Either start run.sh with bash (on windows with git bash or linux bash) or follow these steps

```bash
chmod +x ./run.sh
./run.sh
```

### Windows

Initial CMake

```bash
git submodule update --init --recursive
mkdir build && cd build
cmake .. -G "Visual Studio 14 2015 Win64"
cmake --build . --
```

Execute

```bash
./Debug/Main.exe
./Debug/MainTest.exe
```

### Linux

Initial CMake

```bash
git submodule update --init --recursive
mkdir build && cd build
cmake .. -G "Unix Makefiles"
cmake --build . --
```

Execute

```bash
./Main
./MainTest
```
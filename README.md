# Qt Calculator

A simple calculator application built with Qt5 and C++20.

## Features

- Basic arithmetic operations (+, -, *, /)
- Clear functionality
- Error handling for division by zero
- Modern C++ practices (Rule of Five implementation)

## Requirements

To compile and run this project, you need:

- CMake 3.16 or higher
- Qt5 (Core and Widgets)
- C++20 compatible compiler

## Installing Dependencies

### Ubuntu/Debian:

```bash
# Full development environment
sudo apt install qtcreator qtbase5-dev qt5-qmake qtbase5-dev-tools cmake

# Minimal required packages
sudo apt install qtbase5-dev qt5-qmake cmake
```

### Verifying Qt5 Installation

Check if Qt5 packages are installed and locate them:

```bash
dpkg -l | grep qt5
find /usr -name "Qt5Config.cmake"
```

If Qt5Config.cmake is not found, install the necessary packages:

```bash
sudo apt install qtbase5-dev
```

### Fedora:

```bash
sudo dnf install qt5-qtbase-devel qt5-qttools-devel qt-creator cmake
```

### Arch Linux:

```bash
sudo pacman -S qt5-base qt5-tools qtcreator cmake
```

## Building the Project

### Using CMake (recommended)

```bash
mkdir build && cd build
cmake ..
make
```

### Using QMake (alternative)

```bash
qmake qt-project.pro
make
```

## Running the Application

```bash
./Calculator
```

## Troubleshooting Qt5 Find Issues

If CMake cannot find Qt5, you can specify the Qt5 path manually:

```bash
cmake -DQt5_DIR=/path/to/qt5/lib/cmake/Qt5 ..
```
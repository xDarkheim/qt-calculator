#!/bin/bash

# Check for Qt5 installation
if ! dpkg -l | grep -q qtbase5-dev; then
    echo "Qt5 is not installed. Installing required packages..."
    sudo apt install -y qtbase5-dev qt5-qmake cmake
fi

# Create build directory
mkdir -p build
cd build

# Configure CMake with Qt5 paths
cmake .. \
    -DQt5_DIR=/usr/lib/cmake/Qt5 \
    -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/cmake

# Build the project
make

echo "Build completed. Run the calculator with: ./build/Calculator"

#!/bin/bash
echo "Setteando el entorno de compilación para npk-compiler..."
mkdir -p build
cd build
cmake ..
make
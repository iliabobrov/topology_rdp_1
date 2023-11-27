#!/bin/sh

mkdir build
cd build
cmake ..
make
mv rdp_1 ../run

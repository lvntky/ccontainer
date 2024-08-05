#!/bin/bash

mdkir -p build
cd build/
cmake ..
cd ..
cmake --build build --config Release
./build/ccontainer_tests
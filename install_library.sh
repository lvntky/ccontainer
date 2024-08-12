#!/bin/bash

cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../conan/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build build

sudo cmake --install build
#!/bin/bash

echo "Suppression des fichiers inutile CMake"
rm -f Makefile
rm -rf CMakeFiles
rm -f CMakeCache.txt
rm -rf cmake_install.cmake
rm -f bomberman
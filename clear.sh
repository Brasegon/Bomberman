#!/bin/bash

echo "Suppression des fichiers inutile CMake"
rm -f Makefile
rm -rf CMakeFiles
rm -f CMakeCache.txt
rm -rf cmake_install.cmake
rm -f bomberman
rm -f *.vcxproj*
rm -f *.sln
rm -rf x64
rm -rf Debug
rm -rf *.dir
rm -f *.dll
rm -rf .vs*
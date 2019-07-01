#!/usr/bin/env bash

rm -rfv ./build

mkdir build

cd build

cmake ..

make

./Homework4
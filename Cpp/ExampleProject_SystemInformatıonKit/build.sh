#!/bin/bash
OUTPUT_NAME="SystemTools.out"
echo "[ + ] Starting Build..."
/usr/bin/g++ -fdiagnostics-color=always -g main.cpp -o $OUTPUT_NAME $PWD/include/*.cpp
echo "[ + ] Build Success..."
echo "[ + ] Your File: $OUTPUT_NAME"

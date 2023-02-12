#!/bin/bash

[ ! -d bin ] && mkdir -p bin | echo "bin directory created"

echo "Compiling..."

gcc src/processA.c -lbmp -lncurses -lm -o bin/processA -lrt -pthread
gcc src/processB.c -lbmp -lncurses -lm -o bin/processB -lrt -pthread
gcc src/master.c -lbmp -lncurses -lm -o bin/master -lrt  

echo "Starting program..."
./bin/master

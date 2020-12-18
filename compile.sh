#!/bin/bash

## temporary makefile equivalent

set -e

cd `dirname $0`
echo "Project folder: $PWD"

rm -rf build
mkdir build
DEBUG="-O0 -g"

#TESTS='test_bintree  test_propett'
#for t in $TESTS; do
for t in `cd test && ls test_*.c | sed 's/.c$//'`; do
    echo "==> Compile $t.c"
    gcc $DEBUG -I ./include src/*.c  -o build/$t test/${t}.c
done

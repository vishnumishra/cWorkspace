#! /bin/bash

file=$1
echo ${file}
gcc -c ${file}.c && gcc ${file}.o -o ${file}.exe
${file}.exe

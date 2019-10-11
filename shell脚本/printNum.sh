#!/bin/bash

#方法1 while语句
echo "<while> to loop"
let "n = 0"

while [ $n -lt 10 ]
do
    let "n = n + 1"
    echo $n
done

#方法2 until语句
echo "<until> to loop"
let "n = 0"

until [ $n -eq 10 ]
do
    let "n += 1"
    echo $n
done

#方法3 for语句
echo "<for> to loop"
for i in `seq 1 10`
do
    echo $i
done
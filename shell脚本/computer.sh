#!/bin/bash

# 方法1 expr
echo "<expr> to calculate" 
r=`expr 2 \* 3` #"\"为转义字符
echo $r

# 方法2 将内层括号内运算结果作为外层括号的输出值
echo "\$(()) to calculate"
r=$((2*3))
echo $r

# 方法3 $[]
echo "\$[] to calculate"
r=$[2*3]
echo $r

# 方法4 let
echo "<let> to calculate"
let r=2*3
echo $r
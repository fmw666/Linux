#!/bin/bash
echo "Please choose either N,E,D or Q:"
cat<<-ENDIT
	#[N]ew a file
	#[E]dit a file
	#[D]elete a file
	#[Q]uit
ENDIT
read choice
case "$choice" in
	N) echo "please input a new filename:"
	read value
		touch ${value}	#新建指定名字的文件
	;;
	E) echo "please input a filename:"
	read value
		vi ${value}	#修改指定名字的文件
	;;
	D) echo "please input a filename:"
	read value
		rm ${value}	#删除指定名字的文件
	;;
	Q) TERM=quit
		echo "Quit Successfully"
	;;
esac

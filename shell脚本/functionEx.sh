#!/bin/bash

# Scriptname: do_square
function square
{
    local sq
    let "sq=$1 * $1"
    echo $sq
}                

square $1
# result=$(square $1)
# echo $result
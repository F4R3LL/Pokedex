#!/bin/bash
i=0
j=0
while [ $i -le 50 ]
do
#    convert 6.gif[$i] $i.jpg
    convert -format png $i.jpg
    ((  ++i ))
done

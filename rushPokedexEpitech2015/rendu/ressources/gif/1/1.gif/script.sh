#!/bin/bash
i=0
j=0
while [ $i -le 50 ]
do
    convert 1.gif[$i] $i.png
    ((  ++i ))
done

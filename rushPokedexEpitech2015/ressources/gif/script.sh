#!/bin/bash
i=1
j=0
while [ $i -le 493 ]
do
    convert -strip ./$i/$i.gif/$i.gif ./$i/$i.gif/$i.png
    ((  ++i ))
done

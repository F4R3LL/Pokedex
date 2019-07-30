#!/bin/bash
i=1
while [ $i -le 493 ]
do
   convert ../old/$i.png -colors 256 PNG8:$i.png 
   ((  ++i ))

done

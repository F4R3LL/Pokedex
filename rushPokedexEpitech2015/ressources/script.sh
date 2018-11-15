#!/bin/bash
i=1
c=0;
d=0;
u=1;
while [ $i -le 493 ]
do
    if [ $i = 10 ]; then
	i=1
	d=$d+1;
    fi
    if [ $c = 10 ]; then
	d=0
	$c=$c+1;
    fi
    mv xy-animated/$c$d$u.png
   ((  ++i ))
   ((  ++u ))
done

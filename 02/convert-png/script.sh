#!/bin/bash

# Download images by $LINKS
# Convert to .png

# set -x # debug

source param.conf

cd .build

i=0

for link in "${LINKS[@]}";
do
    echo "---------------- $i -----------"
    wget "$link" -O "img_$i"
    convert "img_$i" "img_$i.png"
    ((++i))
done

for f in *.png; do
    xdg-open "$f" &
done

echo "$MSG done"

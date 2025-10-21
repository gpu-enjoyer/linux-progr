#!/bin/bash

# Download image by $LINK
# Convert to .png

source param.conf

wget "$LINK" -O ".build/cat.jpg"
convert .build/cat.jpg .build/cat.png
xdg-open .build/cat.png

echo "$MSG done"

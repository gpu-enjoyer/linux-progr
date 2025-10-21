#!/bin/bash

### Get the weather from wttr.in by coordinates ###

source param.conf

X=""
Y=""

while getopts "x:y:" opt
do
    case "$opt" in
        x) 
            X="$OPTARG"
            ;;
        y)
            Y="$OPTARG"
            ;;
        *) 
            echo "USAGE: $0 -x \"..\" -y \"..\""
            exit 1
            ;;
    esac
done

curl "https://wttr.in/$X,$Y"

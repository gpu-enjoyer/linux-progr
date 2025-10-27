#!/bin/bash

### Get the weather from wttr.in by coordinates ###

lat=""
long=""

while getopts x:y: args; do
    case $args in
        x)
            lat=$OPTARG
            ;;
        y)
            long=$OPTARG
            ;;
        *) 
            echo "USAGE: $0 -x \"..\" -y \"..\""
            exit 1
            ;;
    esac
done

curl "https://wttr.in/$lat,$long"

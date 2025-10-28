#!/bin/bash

echo -n "\$pipe_out > "

while read -r msg_out < "$pipe_out"; do

    echo "$msg_out"
    echo -n "\$pipe_out > "
    
    echo "next" > "$pipe_token"  ##

done

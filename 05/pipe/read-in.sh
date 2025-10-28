#!/bin/bash

while true; do

    echo -n "\$pipe_in < " >&2

    read -r token < "$pipe_token"  ##

    if read -r msg_in; then
        echo "$msg_in" > "$pipe_in"
    fi

done

#!/bin/bash

export pipe_in="/tmp/pipe-in"
export pipe_out="/tmp/pipe-out"
export pipe_token="/tmp/pipe-token"

rm -f "$pipe_in" "$pipe_out" "$pipe_token"

mkfifo "$pipe_in"
mkfifo "$pipe_out"
mkfifo "$pipe_token"

while read -r line < "$pipe_in"; do
    echo "$line" > "$pipe_out"
done &

( echo "next" > "$pipe_token" ) &

gnome-terminal -- ./read-in.sh &
gnome-terminal -- ./display-out.sh &

wait

rm -f "$pipe_in" "$pipe_out" "$pipe_token"

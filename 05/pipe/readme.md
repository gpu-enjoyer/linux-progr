
# Pipes connection server


## How to run

```bash
./server.sh
```


## Solved trouble

```bash
#!/bin/bash

###  this is server.sh                                  ###
###  bug: too fast access changes of several processes  ###

###  some ideas commented ###

export pipe_in="/tmp/pipe-in"
export pipe_out="/tmp/pipe-out"
# export is_busy="/tmp/is_busy"

[ ! -p "$pipe_in" ] && mkfifo "$pipe_in"
[ ! -p "$pipe_out" ] && mkfifo "$pipe_out"
# [ ! -p "$is_busy" ] && mkfifo "$is_busy"

# man read :
#  read() attempts to read up to 'count' bytes from file
#   descriptor 'fd' into the buffer starting at 'buf'.

# while true; do
#     read -r line < "$is_busy"
#     # detect if is_busy changed
#     # and what to do then?
# done

# in -> out
while read -r line < "$pipe_in"; do
    echo "$line" > "$pipe_out"
done &

gnome-terminal -- ./read-in.sh &
###  #inside:                         ###
###  while read -r msg_in; do         ###
###      echo "$msg_in" > "$pipe_in"  ###
###  done                             ###

gnome-terminal -- ./display-out.sh
###  #inside:                                 ###
###  while read -r msg_out < "$pipe_out"; do  ###
###      echo "$msg_out"                      ###
###  done                                     ###
```

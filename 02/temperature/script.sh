#!/bin/bash

# Check computer devices temperature

source param.conf

sudo find /sys -name "temp*input" | while read line; do
    echo -n "$line: " # path to file
    cat "$line"       # file content
done

echo "$MSG done"

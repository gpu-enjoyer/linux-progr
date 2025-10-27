#!/bin/bash

# Check computer devices temperature

sudo find /sys -name "temp*input" | while read line; do
    echo -n "$line: " # path to file
    cat "$line"       # file content
done

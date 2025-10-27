#!/bin/bash

my-func() {

    if [ "$#" -lt 1 ]; then
        echo "ERROR: 1-st arg: set the output file" >&2
        return 1
    fi

    local output_file="$1"

    shift  # rm 1-st arg

    if [ "$#" -eq 0 ]; then
        echo "ERROR: 2-nd arg: set the command to run" >&2
        return 1
    fi

    echo "my-func.sh: check: $output_file"
    
    "$@" > "$output_file" 2>&1

    # $@          2>&1
    #  all args    stderr > 1-st arg

    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        echo "my-func.sh done"
    else
        echo "ERROR: my-func.sh: $exit_code" >&2
    fi

    return $exit_code
}

my-func /tmp/my-output ls -l
cat /tmp/my-output

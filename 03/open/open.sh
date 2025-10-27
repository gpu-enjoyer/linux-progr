#!/bin/bash

# Open the file in a suitable program

ORIG_DIR=$(pwd)
THIS_DIR=$(dirname "$0")

cd "$THIS_DIR"

for file in files/*;
do
    file_mime=$(file --mime-type -b "$file")
    case "$file_mime" in 
        text/plain)
            code "$file" &
            ;;
        application/pdf)
            firefox "$file" &
            ;;
        image/*)
            xdg-open "$file" &
            ;;
        *)
            echo "=== unknown MIME: $file_mime ==="
            ;;
    esac
done

cd "$ORIG_DIR"

echo "open.sh done"

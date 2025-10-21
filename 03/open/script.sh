#!/bin/bash
# set -x  # for debug

# Open the file in a suitable program

source param.conf

for file in "$DIR"/*;
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
            echo "--------- unknown MIME: $file_mime ---------"
            ;;
    esac
done

echo "$MSG done"

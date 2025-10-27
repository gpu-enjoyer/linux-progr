#!/bin/bash

echo "convert-parallel:"

[ ! -d download ] && ./img-download-par.sh

MAX_JOBS=2

i=0

for link in "${LINKS[@]}"; do
    (
        echo "=== converting: $i ==="
        convert "img_$i" "download/img_$i.png" >/dev/null 2>/dev/null
        # rm -f "download/img_$i"
    ) &
    ((++i))
done

wait

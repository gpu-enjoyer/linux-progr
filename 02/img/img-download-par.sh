#!/bin/bash

echo "download-parallel:"

rm -rf download
mkdir download

LINKS=(
    "https://upload.wikimedia.org/wikipedia/commons/f/f2/Felis_silvestris_silvestris_small_gradual_decrease_of_quality_-_JPEG_compression.jpg"
    "https://www.gstatic.com/webp/gallery/5.sm.webp"
    "https://habrastorage.org/r/w1560/getpro/habr/upload_files/acb/21b/493/acb21b4935bad6db68b579d49c93ec2f.png"
    "https://cdn.shopify.com/s/files/1/0006/5624/4814/files/funnel-web-spider-4865535_1920_large.jpg?v=1584464862"
    "https://fishshell.com/assets/img/Terminal_Logo_CRT_4.svg")

MAX_JOBS=2

i=0

for link in "${LINKS[@]}"; do
    (
        echo "=== downloading: $i ==="
        wget "$link" -O "download/img_$i" >/dev/null 2>/dev/null
    ) &
    ((++i))
done

wait

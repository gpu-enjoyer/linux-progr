#!/bin/bash

# Download images from $LINKS
# Convert to .png

MAX_JOBS=2

LINKS=(
    "https://upload.wikimedia.org/wikipedia/commons/f/f2/Felis_silvestris_silvestris_small_gradual_decrease_of_quality_-_JPEG_compression.jpg"
    "https://www.gstatic.com/webp/gallery/5.sm.webp"
    "https://habrastorage.org/r/w1560/getpro/habr/upload_files/acb/21b/493/acb21b4935bad6db68b579d49c93ec2f.png"
    "https://cdn.shopify.com/s/files/1/0006/5624/4814/files/funnel-web-spider-4865535_1920_large.jpg?v=1584464862"
    "https://fishshell.com/assets/img/Terminal_Logo_CRT_4.svg")

rm -rf img
mkdir img
cd img

i=0

for link in "${LINKS[@]}"; do
    (
        echo "---------------- $i -----------"
        wget "$link" -O "img_$i" >/dev/null 2>/dev/null
        convert "img_$i" "img_$i.png" >/dev/null 2>/dev/null
        rm "img_$i"
    ) &
    ((++i))
done

wait

for f in *.png; do
    xdg-open "$f"
done

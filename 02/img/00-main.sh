#!/bin/bash

ORIG_DIR=$(pwd)
THIS_DIR=$(dirname "$0")

cd "$THIS_DIR"

rm -rf download

./img-convert-par.sh || (echo "ERROR: img-convert-par.sh" && exit 1)

rm -rf download

./img-convert-conv.sh

shopt -s extglob
rm -f download/!(*.png)

# for f in download/*.png; do xdg-open "$f"; done

cd "$ORIG_DIR"

echo "main.sh done"

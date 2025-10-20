#!/bin/bash

THIS_DIR="$(dirname "$0")"
source "$THIS_DIR"/.env

cd "$THIS_DIR"/.. || exit 1

    [ -d build ] && rm -rf build
    mkdir build
    make

cd "$ORIG_DIR" || exit 1

echo -e "$MSG done" && exit 0

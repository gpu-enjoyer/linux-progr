#!/bin/bash

ORIG_DIR=$(pwd)
THIS_DIR=$(dirname "$0")

cd "$THIS_DIR"

./gen-script.sh && ./to-uppercase.sh

cd "$ORIG_DIR"

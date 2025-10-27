#!/bin/bash

ORIG_DIR=$(pwd)
THIS_DIR=$(dirname "$0")

cd "$THIS_DIR"

rm -f to-uppercase.sh
rm -rf test
cp -r 00-test test

cd "$ORIG_DIR"

#!/bin/bash
# set -x  # for debug

# Create symlink

source param.conf

ln -s -f dir my-dir
# ln     - "link"
# -s     - "symbolic"
# -f     - "force"
# dir    - target
# my-dir - link_name

echo "$MSG done"

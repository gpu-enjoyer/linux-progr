#!/bin/bash

find /proc -maxdepth 1 -type d 2>/dev/null

# find /proc
#   search in /proc

# -maxdepth 1
#   limit search depth to 1

# -type d
#   only directories

# 2>/dev/null
#   ignore errors

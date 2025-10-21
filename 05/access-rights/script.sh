#!/bin/bash
# set -x  # for debug

# Change access rights

source param.conf

# files
find . -type f -exec chmod 644 {} +
# 6 (rw-) = 4(read) + 2(write) + 0(execute) -> owner
# 4 (r--) = 4(read) + 0(write) + 0(execute) -> group
# 4 (r--) = 4(read) + 0(write) + 0(execute) -> other

# directories
find . -type d -exec chmod 755 {} +
# 7 (rwx) = 4(r) + 2(w) + 1(x) -> owner
# 5 (r-x) = 4(r) + 0(w) + 1(x) -> group
# 5 (r-x) = 4(r) + 0(w) + 1(x) -> other

echo "$MSG done"

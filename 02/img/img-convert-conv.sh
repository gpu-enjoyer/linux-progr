#!/bin/bash

echo "convert-convey:"

[ ! -d download ] && ./img-download-par.sh

find download/* | xargs -I{} convert {} {}.png

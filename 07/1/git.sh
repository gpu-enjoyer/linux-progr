#!/bin/bash

git init
git add -A
git commit -m "init"
git branch -M main
git remote add origin git@github.com:gpu-enjoyer/test.git
git push -u origin main

#!/bin/bash

git init
git add "hello.txt"
git commit -m "init"
git branch -M main
git remote add origin git@github.com:gpu-enjoyer/test.git
git push -u origin main

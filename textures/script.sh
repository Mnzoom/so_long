#!/bin/sh

files=$(find ./*.png)
for i in $files; do
    base=${i%.png}
    echo "$base.xpm"
    convert "$i" "$base.xpm"
done

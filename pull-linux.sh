#!/bin/bash

set -x
set -e

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

git checkout "linux-raw"

for HEADER in include/uapi/linux/usb/ch9.h; do
        FILENAME=$(basename $HEADER)
	# http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/include/uapi/linux/usb/ch9.h
	rm $FILENAME
	wget "http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/$HEADER"
	git add $FILENAME
done

git commit -m "Updating linux headers."

git checkout $CURRENT_BRANCH

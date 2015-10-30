#!/bin/bash
# Copyright (C) 2015 Google, Inc
#
# This program is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License version 2 as published by the
# Free Software Foundation.
# ---
#
# Switch to the "linux-raw" branch and download USB headers from the Linux
# kernel.
#
# The "linux-raw" branch can then be merged into master (git merge linux-raw)
# to allow git to gracefully merge the modifications we have made to the header
# files.
#
# FIXME: This should get the git revision from the Linux kernel and record it.
#

set -x
set -e

CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)

git checkout "linux-raw"

for HEADER in \
		include/uapi/linux/usb/audio.h \
		include/uapi/linux/usb/cdc.h \
		include/uapi/linux/usb/ch9.h \
		include/uapi/linux/usb/midi.h \
		include/uapi/linux/usb/tmc.h \
		include/uapi/linux/usb/video.h \
		drivers/media/usb/uvc/uvcvideo.h \
		drivers/usb/serial/ftdi_sio.h \
		drivers/usb/serial/ftdi_sio_ids.h \
		; do
        FILENAME=$(basename $HEADER)
	# http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/include/uapi/linux/usb/ch9.h
	if [ -f $FILENAME ]; then
		rm $FILENAME
	fi
	wget "http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/plain/$HEADER"
	git add $FILENAME
done

git commit -m "Updating linux headers."

git checkout $CURRENT_BRANCH

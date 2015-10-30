#!/bin/bash

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

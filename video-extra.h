/*
 * video-extra.h -- Extra definitions for use with include/uapi/linux/usb/video.h
 *
 * Copyright (C) 2015 Google, Inc.
 *
 * Tim 'mithro' Ansell <mithro@mithis.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
#ifndef _USB_VIDEO_EXTRA_H_
#define _USB_VIDEO_EXTRA_H_

#define UVC_BCD_V10 0x0100

// Uncompressed video frames
// #define bmCapabilities D0 - Still image supported
/*
Specifies whether still images are supported at this frame setting. This is
only applicable for VS interfaces with an IN video endpoint using Still Image
Capture Method 1, and should be set to 0 in all other cases.
*/

// #define bmCapabilities D1 - Fixed frame rate
/*
Specifies whether the device provides a fixed frame rate on a stream associated
with this frame descriptor.  Set to 1 if fixed rate is enabled; otherwise, set
to 0.
*/

#endif

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


/* 2.4.3.3. Payload Header Information */

// This bit, when set, indicates the end of the BFH fields.
#define UVC_STREAM_END_OF_HEADER		UVC_STREAM_EOH

// This bit, when set, indicates an error in the device streaming.
#define UVC_STREAM_ERROR			UVC_STREAM_ERR

// This bit, when set, identifies a video sample that belongs to a still image.
#define UVC_STREAM_STILL_IMAGE			UVC_STREAM_STI

// Set to 0.
#define UVC_STREAM_RESERVED			UVC_STREAM_RES

// This bit, when set, indicates the presence of a SCR field
#define UVC_STREAM_SOURCE_CLOCK			UVC_STREAM_SCR

// This bit, when set, indicates the presence of a PTS field.
//#define UVC_STREAM_PTS					(1 << 2)	// Presentation time stamp

// This bit indicates the end of a video frame and is set in the last video
// sample that belongs to a frame.
#define UVC_STREAM_END_OF_FRAME			UVC_STREAM_EOF

// This bit toggles at each frame start boundary and stays constant for the
// rest of the frame.
#define UVC_STREAM_FRAME_ID			UVC_STREAM_FRAME_ID



union uvc_payload_header_bitfield {
	__u8	header;
	struct bitfield {
		__u8 frameId		: 1;
		__u8 endOfFrame		: 1;
		__u8 presentTS		: 1;
		__u8 srcClock		: 1;
		__u8 reserved		: 1;
		__u8 stillImage		: 1;
		__u8 error		: 1;
		__u8 endOfHeader	: 1;
	};
};

struct uvc_payload_header {
	__u8 bLength;
	union uvc_payload_header_bitfield bmBFH;
	// Optional?
	__u32 pts;
	// Optional?
	// Two Part Source Clock reference value
	// D31..D0: Source Time Clock in native device clock units
	// D42..D32: 1KHz SOF token counter
	// D47..D43: Reserved, set to zero.
	__u32 scr;
};

//struct uvc_status_



/*

The structure of each frame is as follows.
 * SOI (Start of Image, 0xFFD8) – required
 * APPn (Application Marker, 0xFFEn) – optional, unless interlaced video is
   used, in which case APP0 segment with "AVI1" marker and Field ID info is
   required.

 * DRI (Define Restart Interval, 0xFFDD) – optional
 * DQT (Define Quantization Table, 0xFFDB) – required
 * DHT (Define Huffman Table, 0xFFC4) – optional, if not specified, standard
   tables as specified in JPEG standard (ISO 10918-1) section K.3.3 are used.

 * SOF0 (Start of Frame, 0xFFC0)- required. All other SOFn segments are not
   supported.

 * SOS (Start of Scan, 0xFFDA) – required
 * Encoded Image Data – required
 * RSTn (Restart count, 0xFFDn) – optional
 * EOI (End of Image, 0xFFD9) - required

The following is required for the image data:
 * Color encoding - YCbCr
 * Bits per pixel - 8 per color component (before filtering/subsampling)
 * Subsampling - 422
 * Baseline sequential DCT (SOF0)
 * All key frames

*/



/**
 * usb_endpoint_num - check if this is the end of the header
 * @epd: header to be checked
 *
 * Returns true if is end of header.
 */
/*
inline bool uvc_stream_end_of_header(const struct uvc_stream_header *header)
{
	return header->bitfield & UVC_STREAM_END_OF_HEADER;
}
*/

#endif

/*
 * ch9-extra.h -- Extra definitions for use with include/uapi/linux/usb/ch9.h
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

#ifndef _USB_CH9_EXTRA_H_
#define _USB_CH9_EXTRA_H_

#define USB_BCD_V10 0x0100
#define USB_BCD_V11 0x0110
#define USB_BCD_V20 0x0200

#define USB_ENDPOINT_NUMBER(x) \
	(x & USB_ENDPOINT_NUMBER_MASK)

// WARNING: Structure packing order of bits is compiler specific and not
// defined in the C specification!
struct usb_endpoint_address {
	__u8 direction	: 1;
	__u8 reserved	: 3;
	__u8 number	: 4;
};

struct usb_endpoint_attributes {
	__u8 max_adjustable	: 1;
	__u8 reserved		: 4;
	__u8 xftertype		: 3;
};

// FIXME: Why isn't this defined in ch9.h?
#define USB_DT_DEVICE_QUALIFIER_SIZE \
	sizeof(struct usb_qualifier_descriptor)

#endif



#define USB_ENDPOINT_NUMBER(x) \
	(x & USB_ENDPOINT_NUMBER_MASK)

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

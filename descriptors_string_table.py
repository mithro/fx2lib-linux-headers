#!/usr/bin/python3

import argparse
import sys

parser = argparse.ArgumentParser(
    description=(
        "Generate a C file containing strings in the format needed "
        "by the USB descriptors."
    ),
)
parser.add_argument(
    "--header",
    action="store_true",
    help="output the C header file (.h)",
)
parser.add_argument(
    "--cfile",
    action="store_true",
    help="output the C body file (.c)b",
)
args = parser.parse_args()

if not (args.header or args.cfile):
    parser.error("No format requested, add --header or --cfile")

strings = [x.strip() for x in sys.stdin.readlines()]

if args.header:
    print("""\
// This file was generated by descriptors_string_table.py with the --header
// parameter
#include <ch9.h>
#include <ch9-extra.h>

#ifndef DESCRIPTORS_STRING_TABLE_H_
#define DESCRIPTORS_STRING_TABLE_H_

struct usb_descriptors_strings {
        struct usb_string_lang {
                __u8 bLength;
                __u8 bDescriptorType;
                __le16 wData[1];
        } language;""")
    for i, string in enumerate(strings):
            print("""\
    struct usb_string_{i} {{
            __u8 bLength;
            __u8 bDescriptorType;
            __le16 wData[{l}];
    }} string{i};""".format(l=len(string), i=i))
    print("""\
};

#endif // DESCRIPTORS_STRING_TABLE_H_
""")

if args.cfile:
    print("""\
    // This file was generated by descriptors_string_table.py with the
    // --cfile parameter
    .strings = {
            // English language header
            .language = {
                    .bLength = sizeof(struct usb_string_lang),
                    .bDescriptorType = USB_DT_STRING,
                    .wData = { 0x0409 }, // 0x0409 is English
            },""")
    for i, string in enumerate(strings):
        data = ["((__le16)('{}'))".format(s) for s in string]

        print("""\
        // "{s}"
        .string{i} = {{
                .bLength = sizeof(struct usb_string_{i}),
                .bDescriptorType = USB_DT_STRING,
                .wData = {{{d}}},
        }},""".format(
            s=string,
            i=i,
            l=len(string),
            d=", ".join(data),
            ))
    print("""\
    },
    """)

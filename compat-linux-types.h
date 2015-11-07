// These defines are used to make Linux Kernel headers compatible with SDCC

#ifndef COMPAT_LINUX_TYPES_H
#define COMPAT_LINUX_TYPES_H

#ifndef SDCC
#include <stdint.h>

#define BYTE int8_t
#define WORD int16_t
#define DWORD int32_t
#define __code
#define __xdata
#define __at(x)

int main() {
	return 0;
}

#else
#include <fx2types.h>
#endif

/* The 8051 is an 8bit processor, so doesn't actually have any endian
 * naturally, instead the endian comes from the compiler. 
 *
 * sdcc choses to be little endian, as does the USB specification.
 */


#define __u8    BYTE
#define __u16   __le16
#define __le16  WORD
#define __u32   __le32
#define __le32  DWORD

#define __le16_to_cpu

// Use a macro to make __attribute__ stuff disappear. sdcc always generates
// "packed" structures.
#define __attribute__(x)

#endif // COMPAT_LINUX_TYPES_H

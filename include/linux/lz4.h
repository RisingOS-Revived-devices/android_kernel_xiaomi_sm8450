/* SPDX-License-Identifier: BSD-2-Clause */
// LZ4 compatibility wrapper for Linux kernel

#ifndef __LINUX_LZ4_H__
#define __LINUX_LZ4_H__

#include "../../lib/lz4/lz4.h"
#include "../../lib/lz4/lz4hc.h"

#define LZ4_MEM_COMPRESS	LZ4_STREAM_MINSIZE
#define LZ4HC_MEM_COMPRESS	LZ4_STREAMHC_MINSIZE

/* old kernel range; f2fs stores it on disk, lz4hc clamps >12 to 12 */
#define LZ4HC_MIN_CLEVEL	3
#define LZ4HC_MAX_CLEVEL	16

#endif

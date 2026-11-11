/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_UNAME_SPOOF_H
#define _LINUX_UNAME_SPOOF_H

#include <linux/kernel.h>
#include <linux/version.h>

/*
 * A spoofed release must keep the running kernel's major.minor: ART reads it
 * from uname() and aborts zygote when it does not match the kernel features
 * (e.g. a 5.x release on a 6.x kernel that offers UFFD_FEATURE_MOVE).
 */
static inline bool uname_release_matches_kernel(const char *release)
{
	unsigned int major, minor;

	return sscanf(release, "%u.%u", &major, &minor) == 2 &&
	       major == LINUX_VERSION_MAJOR &&
	       minor == LINUX_VERSION_PATCHLEVEL;
}

#ifdef CONFIG_UNAME_SPOOF
bool uname_spoof_should_spoof(void);
const char *uname_spoof_get_release(void);
const char *uname_spoof_get_version(void);
#else
static inline bool uname_spoof_should_spoof(void) { return false; }
static inline const char *uname_spoof_get_release(void) { return NULL; }
static inline const char *uname_spoof_get_version(void) { return NULL; }
#endif

#endif /* _LINUX_UNAME_SPOOF_H */

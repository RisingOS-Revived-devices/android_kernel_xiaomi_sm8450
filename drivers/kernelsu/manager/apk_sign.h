#ifndef __KSU_H_APK_V2_SIGN
#define __KSU_H_APK_V2_SIGN

#include <linux/types.h>

bool is_manager_apk(char *path);
// Overrides for the manager last matched by is_manager_apk(), 0 for none.
u32 ksu_get_matched_manager_version(void);
u32 ksu_get_matched_manager_uapi(void);
int get_pkg_from_apk_dir_path(char *pkg, const char *path);

#endif

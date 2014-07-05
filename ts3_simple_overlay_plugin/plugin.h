#ifndef PLUGIN_H
#define PLUGIN_H

#include "ts3_overlay_global.h"

/* Required functions */


#ifdef __cplusplus
extern "C" {
#endif

TS3_LIB_EXPORT const char* ts3plugin_name();
TS3_LIB_EXPORT const char* ts3plugin_version();
TS3_LIB_EXPORT int ts3plugin_apiVersion();
TS3_LIB_EXPORT const char* ts3plugin_author();
TS3_LIB_EXPORT const char* ts3plugin_description();
TS3_LIB_EXPORT void ts3plugin_setFunctionPointers(const struct TS3Functions funcs);
TS3_LIB_EXPORT int ts3plugin_init();
TS3_LIB_EXPORT void ts3plugin_shutdown();

#ifdef __cplusplus
}
#endif

#endif // PLUGIN_H

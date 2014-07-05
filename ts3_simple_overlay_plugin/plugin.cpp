#include "plugin.h"


#include "includes/public_errors.h"
#include "includes/ts3_functions.h"

#include "ts3_overlay.h"

#define PLUGIN_API_VERSION 20
#define PATH_BUFSIZE 512

Ts3_overlay *pluginObj;

//********************************** Required functions ************************************
//
// If any of these required functions is not implemented, TS3 will refuse to load the plugin
//

// Unique name identifying this plugin
const char* ts3plugin_name() {
    return "TS3 Simple Overlay";
}

// Plugin version
const char* ts3plugin_version() {
    return "1.0";
}

// Plugin API version. Must be the same as the clients API major version, else the plugin fails to load.
int ts3plugin_apiVersion() {
    return PLUGIN_API_VERSION;
}

// Plugin author
const char* ts3plugin_author() {
    return "riuson";
}

// Plugin description
const char* ts3plugin_description() {
    return "This plugin just displays overlay.\nWritten on Qt " QT_VERSION_STR;
}

// Set TeamSpeak 3 callback functions
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
    //ts3Functions = funcs;
}

//
// Custom code called right after loading the plugin. Returns 0 on success, 1 on failure.
// If the function returns 1 on failure, the plugin will be unloaded again.
//
int ts3plugin_init() {

    pluginObj = new Ts3_overlay();

    return 0;
    // 0 = success, 1 = failure, -2 = failure but client will not show a "failed to load" warning
    // -2 is a very special case and should only be used if a plugin displays a dialog (e.g. overlay) asking the user to disable
    // the plugin again, avoiding the show another dialog by the client telling the user the plugin failed to load.
    // For normal case, if a plugin really failed to load because of an error, the correct return value is 1.
}

// Custom code called right before the plugin is unloaded
void ts3plugin_shutdown() {

    delete pluginObj;
    pluginObj = NULL;

    // Free pluginID if we registered it
    //if(pluginID) {
    //    free(pluginID);
    //    pluginID = NULL;
    //}
}

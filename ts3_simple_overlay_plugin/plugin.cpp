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

//****************************** Optional functions ********************************
//
// Following functions are optional, if not needed you don't need to implement them.
//

// Tell client if plugin offers a configuration window. If this function is not implemented, it's an assumed "does not offer" (PLUGIN_OFFERS_NO_CONFIGURE). */
int ts3plugin_offersConfigure() {
    // Return values:
    // PLUGIN_OFFERS_NO_CONFIGURE - Plugin does not implement ts3plugin_configure
    // PLUGIN_OFFERS_CONFIGURE_NEW_THREAD - Plugin does implement ts3plugin_configure and requests to run this function in an own thread
    // PLUGIN_OFFERS_CONFIGURE_QT_THREAD - Plugin does implement ts3plugin_configure and requests to run this function in the Qt GUI thread
    return PLUGIN_OFFERS_CONFIGURE_QT_THREAD;
}

/* Plugin might offer a configuration window. If ts3plugin_offersConfigure returns 0, this function does not need to be implemented. */
void ts3plugin_configure(void* handle, void* qParentWidget) {
    Q_UNUSED(handle);

    if (pluginObj != NULL) {
        QWidget *parent = (QWidget*)qParentWidget;
        pluginObj->runSettings(parent);
    }
}

// Helper function to create a hotkey
//static struct PluginHotkey* createHotkey(const char* keyword, const char* description) {
//    struct PluginHotkey* hotkey = (struct PluginHotkey*)malloc(sizeof(struct PluginHotkey));
//    _strcpy(hotkey->keyword, PLUGIN_HOTKEY_BUFSZ, keyword);
//    _strcpy(hotkey->description, PLUGIN_HOTKEY_BUFSZ, description);
//    return hotkey;
//}

// Some makros to make the code to create hotkeys a bit more readable
#define BEGIN_CREATE_HOTKEYS(x) const size_t sz = x + 1; size_t n = 0; *hotkeys = (struct PluginHotkey**)malloc(sizeof(struct PluginHotkey*) * sz);
#define CREATE_HOTKEY(a, b) (*hotkeys)[n++] = createHotkey(a, b);
#define END_CREATE_HOTKEYS (*hotkeys)[n++] = NULL; assert(n == sz);

//
// Initialize plugin hotkeys. If your plugin does not use this feature, this function can be omitted.
// Hotkeys require ts3plugin_registerPluginID and ts3plugin_freeMemory to be implemented.
// This function is automatically called by the client after ts3plugin_init.
//
//void ts3plugin_initHotkeys(struct PluginHotkey*** hotkeys) {
    // Register hotkeys giving a keyword and a description.
    // The keyword will be later passed to ts3plugin_onHotkeyEvent to identify which hotkey was triggered.
    // The description is shown in the clients hotkey dialog. */

    //BEGIN_CREATE_HOTKEYS(5); /* Create n hotkeys. Size must be correct for allocating memory. */
    //    CREATE_HOTKEY("TS3_NEXT_TAB_AND_TALK_START", "Next Tab and Talk Start");
    //    CREATE_HOTKEY("TS3_NEXT_TAB_AND_WHISPER_ALL_CC_START", "Next Tab and Whisper all Channel Commanders Start");
    //    CREATE_HOTKEY("TS3_SWITCH_N_TALK_END", "SnT Stop");
    //    CREATE_HOTKEY("CHANNEL_MUTER", "Toggle Channel Mute");
    //    CREATE_HOTKEY("PS_TOGGLE", "Toggle Priority Speaker");
    //END_CREATE_HOTKEYS;

    // The client will call ts3plugin_freeMemory to release all allocated memory
//}

void ts3plugin_onTalkStatusChangeEvent(uint64 serverConnectionHandlerID, int status, int isReceivedWhisper, anyID clientID)
{
    if (pluginObj != NULL) {
        pluginObj->onTalkStatusChangeEvent(serverConnectionHandlerID, status, isReceivedWhisper, clientID);
    }
}

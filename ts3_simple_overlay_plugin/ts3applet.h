#include <public_definitions.h>

void ts3_applet_init();
void ts3_applet_shutdown();
void ts3_applet_newMessage(wchar_t *sender, wchar_t *message, anyID targetMode);
void ts3_applet_updateChannel(wchar_t *channelName);
void ts3_applet_updateSpeaking();

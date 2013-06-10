#include <public_definitions.h>

void ts3applet_init();
void ts3applet_shutdown();
void ts3applet_updateChannel();
void ts3applet_updateSpeaking();
void ts3applet_newMessage(wchar_t* sender, wchar_t* message, anyID targetMode);

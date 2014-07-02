#include <public_definitions.h>

void ts3g19_init();
void ts3g19_shutdown();
void ts3g19_newMessage(wchar_t *sender, wchar_t *message, anyID targetMode);
void ts3g19_updateChannel(wchar_t *channelName);
void ts3g19_updateSpeaking();

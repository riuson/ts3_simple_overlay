/*
* TeamSpeak 3 demo plugin
*
* Copyright (c) 2008-2013 TeamSpeak Systems GmbH
*/

#include "stdafx.h"

#include "public_errors.h"
#include "public_errors_rare.h"
#include "public_definitions.h"
#include "public_rare_definitions.h"
#include "ts3_functions.h"
#include "plugin.h"
#include "ts3applet.h"

static struct TS3Functions ts3Functions;

#define PLUGIN_API_VERSION 19

#define PATH_BUFSIZE 512

static char* pluginID = NULL;

/*********************************** Required functions ************************************/
/*
* If any of these required functions is not implemented, TS3 will refuse to load the plugin
*/

/* Unique name identifying this plugin */
const char* ts3plugin_name() {
	return "G19 Applet";
}

/* Plugin version */
const char* ts3plugin_version() {
	return "1.0";
}

/* Plugin API version. Must be the same as the clients API major version, else the plugin fails to load. */
int ts3plugin_apiVersion() {
	return PLUGIN_API_VERSION;
}

/* Plugin author */
const char* ts3plugin_author() {
	return "Fabian Parzefall";
}

/* Plugin description */
const char* ts3plugin_description() {
	return "This plugin prints some information on your Logitech G19 screen.";
}

/* Set TeamSpeak 3 callback functions */
void ts3plugin_setFunctionPointers(const struct TS3Functions funcs) {
	ts3Functions = funcs;
}

/*
* Custom code called right after loading the plugin. Returns 0 on success, 1 on failure.
* If the function returns 1 on failure, the plugin will be unloaded again.
*/
int ts3plugin_init() {

	ts3g19_init();

	return 0;  /* 0 = success, 1 = failure, -2 = failure but client will not show a "failed to load" warning */
	/* -2 is a very special case and should only be used if a plugin displays a dialog (e.g. overlay) asking the user to disable
	* the plugin again, avoiding the show another dialog by the client telling the user the plugin failed to load.
	* For normal case, if a plugin really failed to load because of an error, the correct return value is 1. */
}

/* Custom code called right before the plugin is unloaded */
void ts3plugin_shutdown() {
	ts3g19_shutdown();

	/* Free pluginID if we registered it */
	if(pluginID) {
		free(pluginID);
		pluginID = NULL;
	}
}

/************************** TeamSpeak callbacks ***************************/
/*
* Following functions are optional, feel free to remove unused callbacks.
* See the clientlib documentation for details on each function.
*/

/* Clientlib */

int ts3plugin_onTextMessageEvent(uint64 serverConnectionHandlerID, anyID targetMode, anyID toID, anyID fromID, const char* fromName, const char* fromUniqueIdentifier, const char* message, int ffIgnored) {
	/* Friend/Foe manager has ignored the message, so ignore here as well. */
	if(ffIgnored) {
		return 0; /* Client will ignore the message anyways, so return value here doesn't matter */
	}

	wchar_t *sender, *wcmessage;
	int size;

	// Convert the multibyte strings to wide chars
	size = MultiByteToWideChar(CP_UTF8, 0, fromName, -1, NULL, 0);
	sender = new wchar_t[size];
	MultiByteToWideChar(CP_UTF8, 0, fromName, -1, sender, size);

	size = MultiByteToWideChar(CP_UTF8, 0, message, -1, NULL, 0);
	wcmessage = new wchar_t[size];
	MultiByteToWideChar(CP_UTF8, 0, message, -1, wcmessage, size);

	// Push the message to G19
	ts3g19_newMessage(sender, wcmessage, targetMode);

	// Free the memory
	delete[] sender, wcmessage;

	return 0;  /* 0 = handle normally, 1 = client will ignore the text message */
}

void ts3plugin_onClientMoveEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, const char* moveMessage) {
	char *channelName;
	wchar_t *wcChannelName;
	int size;

	// Get channel name
	ts3Functions.getChannelVariableAsString(serverConnectionHandlerID, newChannelID, CHANNEL_NAME, &channelName);

	// Convert the channel name to wide chars
	size = MultiByteToWideChar(CP_UTF8, 0, channelName, -1, NULL, 0);
	wcChannelName = new wchar_t[size];
	MultiByteToWideChar(CP_UTF8, 0, channelName, -1, wcChannelName, size);

	// Write it on G19
	ts3g19_updateChannel(wcChannelName);

	// Free the memory
	ts3Functions.freeMemory(channelName);
	delete[] wcChannelName;
}

void ts3plugin_onClientMoveMovedEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID moverID, const char* moverName, const char* moverUniqueIdentifier, const char* moveMessage) {
	char *channelName;
	wchar_t *wcChannelName;
	int size;

	// Get channel name
	ts3Functions.getChannelVariableAsString(serverConnectionHandlerID, newChannelID, CHANNEL_NAME, &channelName);

	// Convert the channel name to wide chars
	size = MultiByteToWideChar(CP_UTF8, 0, channelName, -1, NULL, 0);
	wcChannelName = new wchar_t[size];
	MultiByteToWideChar(CP_UTF8, 0, channelName, -1, wcChannelName, size);

	// Write it on G19
	ts3g19_updateChannel(wcChannelName);

	// Free the memory
	ts3Functions.freeMemory(channelName);
	delete[] wcChannelName;
}

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

/* Optional functions */
TS3_LIB_EXPORT int ts3plugin_offersConfigure();
TS3_LIB_EXPORT void ts3plugin_configure(void* handle, void* qParentWidget);
//TS3_LIB_EXPORT void ts3plugin_registerPluginID(const char* id);
//TS3_LIB_EXPORT const char* ts3plugin_commandKeyword();
//TS3_LIB_EXPORT int ts3plugin_processCommand(uint64 serverConnectionHandlerID, const char* command);
//TS3_LIB_EXPORT void ts3plugin_currentServerConnectionChanged(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT const char* ts3plugin_infoTitle();
//TS3_LIB_EXPORT void ts3plugin_infoData(uint64 serverConnectionHandlerID, uint64 id, enum PluginItemType type, char** data);
//TS3_LIB_EXPORT void ts3plugin_freeMemory(void* data);
//TS3_LIB_EXPORT int ts3plugin_requestAutoload();
//TS3_LIB_EXPORT void ts3plugin_initMenus(struct PluginMenuItem*** menuItems, char** menuIcon);
//TS3_LIB_EXPORT void ts3plugin_initHotkeys(struct PluginHotkey*** hotkeys);

// Clientlib
TS3_LIB_EXPORT void ts3plugin_onConnectStatusChangeEvent(uint64 serverConnectionHandlerID, int newStatus, unsigned int errorNumber);
//TS3_LIB_EXPORT void ts3plugin_onNewChannelEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 channelParentID);
//TS3_LIB_EXPORT void ts3plugin_onNewChannelCreatedEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 channelParentID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier);
//TS3_LIB_EXPORT void ts3plugin_onDelChannelEvent(uint64 serverConnectionHandlerID, uint64 channelID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier);
//TS3_LIB_EXPORT void ts3plugin_onChannelMoveEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 newChannelParentID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier);
//TS3_LIB_EXPORT void ts3plugin_onUpdateChannelEvent(uint64 serverConnectionHandlerID, uint64 channelID);
//TS3_LIB_EXPORT void ts3plugin_onUpdateChannelEditedEvent(uint64 serverConnectionHandlerID, uint64 channelID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier);
//TS3_LIB_EXPORT void ts3plugin_onUpdateClientEvent(uint64 serverConnectionHandlerID, anyID clientID, anyID invokerID, const char* invokerName, const char* invokerUniqueIdentifier);
//TS3_LIB_EXPORT void ts3plugin_onClientMoveEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, const char* moveMessage);
//TS3_LIB_EXPORT void ts3plugin_onClientMoveSubscriptionEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility);
//TS3_LIB_EXPORT void ts3plugin_onClientMoveTimeoutEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, const char* timeoutMessage);
//TS3_LIB_EXPORT void ts3plugin_onClientMoveMovedEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID moverID, const char* moverName, const char* moverUniqueIdentifier, const char* moveMessage);
//TS3_LIB_EXPORT void ts3plugin_onClientKickFromChannelEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID kickerID, const char* kickerName, const char* kickerUniqueIdentifier, const char* kickMessage);
//TS3_LIB_EXPORT void ts3plugin_onClientKickFromServerEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID kickerID, const char* kickerName, const char* kickerUniqueIdentifier, const char* kickMessage);
//TS3_LIB_EXPORT void ts3plugin_onClientIDsEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, anyID clientID, const char* clientName);
//TS3_LIB_EXPORT void ts3plugin_onClientIDsFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onServerEditedEvent(uint64 serverConnectionHandlerID, anyID editerID, const char* editerName, const char* editerUniqueIdentifier);
//TS3_LIB_EXPORT void ts3plugin_onServerUpdatedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT int ts3plugin_onServerErrorEvent(uint64 serverConnectionHandlerID, const char* errorMessage, unsigned int error, const char* returnCode, const char* extraMessage);
//TS3_LIB_EXPORT void ts3plugin_onServerStopEvent(uint64 serverConnectionHandlerID, const char* shutdownMessage);
//TS3_LIB_EXPORT int ts3plugin_onTextMessageEvent(uint64 serverConnectionHandlerID, anyID targetMode, anyID toID, anyID fromID, const char* fromName, const char* fromUniqueIdentifier, const char* message, int ffIgnored);
TS3_LIB_EXPORT void ts3plugin_onTalkStatusChangeEvent(uint64 serverConnectionHandlerID, int status, int isReceivedWhisper, anyID clientID);
//TS3_LIB_EXPORT void ts3plugin_onConnectionInfoEvent(uint64 serverConnectionHandlerID, anyID clientID);
//TS3_LIB_EXPORT void ts3plugin_onServerConnectionInfoEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onChannelSubscribeEvent(uint64 serverConnectionHandlerID, uint64 channelID);
//TS3_LIB_EXPORT void ts3plugin_onChannelSubscribeFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onChannelUnsubscribeEvent(uint64 serverConnectionHandlerID, uint64 channelID);
//TS3_LIB_EXPORT void ts3plugin_onChannelUnsubscribeFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onChannelDescriptionUpdateEvent(uint64 serverConnectionHandlerID, uint64 channelID);
//TS3_LIB_EXPORT void ts3plugin_onChannelPasswordChangedEvent(uint64 serverConnectionHandlerID, uint64 channelID);
//TS3_LIB_EXPORT void ts3plugin_onPlaybackShutdownCompleteEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onSoundDeviceListChangedEvent(const char* modeID, int playOrCap);
//TS3_LIB_EXPORT void ts3plugin_onEditPlaybackVoiceDataEvent(uint64 serverConnectionHandlerID, anyID clientID, short* samples, int sampleCount, int channels);
//TS3_LIB_EXPORT void ts3plugin_onEditPostProcessVoiceDataEvent(uint64 serverConnectionHandlerID, anyID clientID, short* samples, int sampleCount, int channels, const unsigned int* channelSpeakerArray, unsigned int* channelFillMask);
//TS3_LIB_EXPORT void ts3plugin_onEditMixedPlaybackVoiceDataEvent(uint64 serverConnectionHandlerID, short* samples, int sampleCount, int channels, const unsigned int* channelSpeakerArray, unsigned int* channelFillMask);
//TS3_LIB_EXPORT void ts3plugin_onEditCapturedVoiceDataEvent(uint64 serverConnectionHandlerID, short* samples, int sampleCount, int channels, int* edited);
//TS3_LIB_EXPORT void ts3plugin_onCustom3dRolloffCalculationClientEvent(uint64 serverConnectionHandlerID, anyID clientID, float distance, float* volume);
//TS3_LIB_EXPORT void ts3plugin_onCustom3dRolloffCalculationWaveEvent(uint64 serverConnectionHandlerID, uint64 waveHandle, float distance, float* volume);
//TS3_LIB_EXPORT void ts3plugin_onUserLoggingMessageEvent(const char* logMessage, int logLevel, const char* logChannel, uint64 logID, const char* logTime, const char* completeLogString);

// Clientlib rare
//TS3_LIB_EXPORT void ts3plugin_onClientBanFromServerEvent(uint64 serverConnectionHandlerID, anyID clientID, uint64 oldChannelID, uint64 newChannelID, int visibility, anyID kickerID, const char* kickerName, const char* kickerUniqueIdentifier, uint64 time, const char* kickMessage);
//TS3_LIB_EXPORT int ts3plugin_onClientPokeEvent(uint64 serverConnectionHandlerID, anyID fromClientID, const char* pokerName, const char* pokerUniqueIdentity, const char* message, int ffIgnored);
//TS3_LIB_EXPORT void ts3plugin_onClientSelfVariableUpdateEvent(uint64 serverConnectionHandlerID, int flag, const char* oldValue, const char* newValue);
//TS3_LIB_EXPORT void ts3plugin_onFileListEvent(uint64 serverConnectionHandlerID, uint64 channelID, const char* path, const char* name, uint64 size, uint64 datetime, int type, uint64 incompletesize, const char* returnCode);
//TS3_LIB_EXPORT void ts3plugin_onFileListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelID, const char* path);
//TS3_LIB_EXPORT void ts3plugin_onFileInfoEvent(uint64 serverConnectionHandlerID, uint64 channelID, const char* name, uint64 size, uint64 datetime);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupListEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID, const char* name, int type, int iconID, int saveDB);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupListFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupByClientIDEvent(uint64 serverConnectionHandlerID, const char* name, uint64 serverGroupList, uint64 clientDatabaseID);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupPermListEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID, unsigned int permissionID, int permissionValue, int permissionNegated, int permissionSkip);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupClientListEvent(uint64 serverConnectionHandlerID, uint64 serverGroupID, uint64 clientDatabaseID, const char* clientNameIdentifier, const char* clientUniqueID);
//TS3_LIB_EXPORT void ts3plugin_onChannelGroupListEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID, const char* name, int type, int iconID, int saveDB);
//TS3_LIB_EXPORT void ts3plugin_onChannelGroupListFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onChannelGroupPermListEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID, unsigned int permissionID, int permissionValue, int permissionNegated, int permissionSkip);
//TS3_LIB_EXPORT void ts3plugin_onChannelGroupPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID);
//TS3_LIB_EXPORT void ts3plugin_onChannelPermListEvent(uint64 serverConnectionHandlerID, uint64 channelID, unsigned int permissionID, int permissionValue, int permissionNegated, int permissionSkip);
//TS3_LIB_EXPORT void ts3plugin_onChannelPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelID);
//TS3_LIB_EXPORT void ts3plugin_onClientPermListEvent(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, unsigned int permissionID, int permissionValue, int permissionNegated, int permissionSkip);
//TS3_LIB_EXPORT void ts3plugin_onClientPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 clientDatabaseID);
//TS3_LIB_EXPORT void ts3plugin_onChannelClientPermListEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID, unsigned int permissionID, int permissionValue, int permissionNegated, int permissionSkip);
//TS3_LIB_EXPORT void ts3plugin_onChannelClientPermListFinishedEvent(uint64 serverConnectionHandlerID, uint64 channelID, uint64 clientDatabaseID);
//TS3_LIB_EXPORT void ts3plugin_onClientChannelGroupChangedEvent(uint64 serverConnectionHandlerID, uint64 channelGroupID, uint64 channelID, anyID clientID, anyID invokerClientID, const char* invokerName, const char* invokerUniqueIdentity);
//TS3_LIB_EXPORT int ts3plugin_onServerPermissionErrorEvent(uint64 serverConnectionHandlerID, const char* errorMessage, unsigned int error, const char* returnCode, unsigned int failedPermissionID);
//TS3_LIB_EXPORT void ts3plugin_onPermissionListGroupEndIDEvent(uint64 serverConnectionHandlerID, unsigned int groupEndID);
//TS3_LIB_EXPORT void ts3plugin_onPermissionListEvent(uint64 serverConnectionHandlerID, unsigned int permissionID, const char* permissionName, const char* permissionDescription);
//TS3_LIB_EXPORT void ts3plugin_onPermissionListFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onPermissionOverviewEvent(uint64 serverConnectionHandlerID, uint64 clientDatabaseID, uint64 channelID, int overviewType, uint64 overviewID1, uint64 overviewID2, unsigned int permissionID, int permissionValue, int permissionNegated, int permissionSkip);
//TS3_LIB_EXPORT void ts3plugin_onPermissionOverviewFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupClientAddedEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientName, const char* clientUniqueIdentity, uint64 serverGroupID, anyID invokerClientID, const char* invokerName, const char* invokerUniqueIdentity);
//TS3_LIB_EXPORT void ts3plugin_onServerGroupClientDeletedEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientName, const char* clientUniqueIdentity, uint64 serverGroupID, anyID invokerClientID, const char* invokerName, const char* invokerUniqueIdentity);
//TS3_LIB_EXPORT void ts3plugin_onClientNeededPermissionsEvent(uint64 serverConnectionHandlerID, unsigned int permissionID, int permissionValue);
//TS3_LIB_EXPORT void ts3plugin_onClientNeededPermissionsFinishedEvent(uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onFileTransferStatusEvent(anyID transferID, unsigned int status, const char* statusMessage, uint64 remotefileSize, uint64 serverConnectionHandlerID);
//TS3_LIB_EXPORT void ts3plugin_onClientChatClosedEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientUniqueIdentity);
//TS3_LIB_EXPORT void ts3plugin_onClientChatComposingEvent(uint64 serverConnectionHandlerID, anyID clientID, const char* clientUniqueIdentity);
//TS3_LIB_EXPORT void ts3plugin_onServerLogEvent(uint64 serverConnectionHandlerID, const char* logMsg);
//TS3_LIB_EXPORT void ts3plugin_onServerLogFinishedEvent(uint64 serverConnectionHandlerID, uint64 lastPos, uint64 fileSize);
//TS3_LIB_EXPORT void ts3plugin_onMessageListEvent(uint64 serverConnectionHandlerID, uint64 messageID, const char* fromClientUniqueIdentity, const char* subject, uint64 timestamp, int flagRead);
//TS3_LIB_EXPORT void ts3plugin_onMessageGetEvent(uint64 serverConnectionHandlerID, uint64 messageID, const char* fromClientUniqueIdentity, const char* subject, const char* message, uint64 timestamp);
//TS3_LIB_EXPORT void ts3plugin_onClientDBIDfromUIDEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, uint64 clientDatabaseID);
//TS3_LIB_EXPORT void ts3plugin_onClientNamefromUIDEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, uint64 clientDatabaseID, const char* clientNickName);
//TS3_LIB_EXPORT void ts3plugin_onClientNamefromDBIDEvent(uint64 serverConnectionHandlerID, const char* uniqueClientIdentifier, uint64 clientDatabaseID, const char* clientNickName);
//TS3_LIB_EXPORT void ts3plugin_onComplainListEvent(uint64 serverConnectionHandlerID, uint64 targetClientDatabaseID, const char* targetClientNickName, uint64 fromClientDatabaseID, const char* fromClientNickName, const char* complainReason, uint64 timestamp);
//TS3_LIB_EXPORT void ts3plugin_onBanListEvent(uint64 serverConnectionHandlerID, uint64 banid, const char* ip, const char* name, const char* uid, uint64 creationTime, uint64 durationTime, const char* invokerName, uint64 invokercldbid, const char* invokeruid, const char* reason, int numberOfEnforcements, const char* lastNickName);
//TS3_LIB_EXPORT void ts3plugin_onClientServerQueryLoginPasswordEvent(uint64 serverConnectionHandlerID, const char* loginPassword);
//TS3_LIB_EXPORT void ts3plugin_onPluginCommandEvent(uint64 serverConnectionHandlerID, const char* pluginName, const char* pluginCommand);
//TS3_LIB_EXPORT void ts3plugin_onIncomingClientQueryEvent(uint64 serverConnectionHandlerID, const char* commandText);
//TS3_LIB_EXPORT void ts3plugin_onServerTemporaryPasswordListEvent(uint64 serverConnectionHandlerID, const char* clientNickname, const char* uniqueClientIdentifier, const char* description, const char* password, uint64 timestampStart, uint64 timestampEnd, uint64 targetChannelID, const char* targetChannelPW);

// Client UI callbacks
//TS3_LIB_EXPORT void ts3plugin_onAvatarUpdated(uint64 serverConnectionHandlerID, anyID clientID, const char* avatarPath);
//TS3_LIB_EXPORT void ts3plugin_onMenuItemEvent(uint64 serverConnectionHandlerID, enum PluginMenuType type, int menuItemID, uint64 selectedItemID);
//TS3_LIB_EXPORT void ts3plugin_onHotkeyEvent(const char* keyword);
//TS3_LIB_EXPORT void ts3plugin_onHotkeyRecordedEvent(const char* keyword, const char* key);
//TS3_LIB_EXPORT void ts3plugin_onClientDisplayNameChanged(uint64 serverConnectionHandlerID, anyID clientID, const char* displayName, const char* uniqueClientIdentifier);


#ifdef __cplusplus
}
#endif

#endif // PLUGIN_H

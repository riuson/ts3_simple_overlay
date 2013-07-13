// TS3 Applet.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include "ts3applet.h"
#include <LogitechLcd.h>
#include <public_definitions.h>

#define BITMAP_SIZE (307200)
#define CHARS_PRO_LINE (29)
#define NUMBER_MESSAGES (3)

static struct message
{
	wchar_t Sender[30]; // One line for the sender.
	wchar_t Message[146]; // Five lines for the message. Everything behind will be cutted off.
	anyID TargetMode; // The target mode.
} Messages[NUMBER_MESSAGES];

void ts3g19_init()
{
	BYTE colorBitmap[BITMAP_SIZE];

	// Init
	LogiLcdInit(L"TS3 Applet", LOGI_LCD_TYPE_COLOR);
	LogiLcdColorSetTitle(L"TeamSpeak 3", 0, 0, 0);

	// Init background
	for(int i = 0; i < BITMAP_SIZE; i++)
	{
		colorBitmap[i] = 245;
	}
	LogiLcdColorSetBackground(colorBitmap);

	// Get it on screen
	LogiLcdUpdate();

	// Initialize the messages array
	for(int i = 0; i < NUMBER_MESSAGES; i++)
	{
		Messages[i].Sender[29] = L'\0';
		Messages[i].Message[145] = L'\0';
	}
}

void ts3g19_shutdown()
{
	LogiLcdShutdown();
}

void ts3g19_newMessage(wchar_t *sender, wchar_t *message, anyID TargetMode)
{
	// The message on the bottom of display.
	static short index = NUMBER_MESSAGES - 1;
	// The current message, that is being drawn.
	int display;
	// The color of the message.
	int r = 0, g = 0, b = 0;

	if(index == NUMBER_MESSAGES - 1)
		index = 0;
	else
		index++;

	display = index;

	// Copy the message from the parameters to the message[] array.
	wcsncpy(Messages[index].Sender, sender, 29);
	wcsncpy(Messages[index].Message, message, 145);
	Messages[index].TargetMode = TargetMode;

	for(int i = 2; i >= 0; i--)
	{
		switch(Messages[display].TargetMode)
		{
		case TextMessageTarget_CLIENT:
			r = 25;
			g = 50;
			b = 156;
			break;
		case TextMessageTarget_SERVER:
			r = 255;
			g = 0;
			b = 72;
			break;
		default:
			r = 0;
			g = 0;
			b = 0;
			break;
		}

		LogiLcdColorSetText(2 * i + 2, Messages[display].Sender, r, g, b);
		LogiLcdColorSetText(2 * i + 3, Messages[display].Message, 0, 0, 0);

		if(display == 0)
			display = NUMBER_MESSAGES - 1;
		else
			display--;
	}

	LogiLcdUpdate();
}

void ts3g19_updateChannel(wchar_t *channelName)
{
	LogiLcdColorSetTitle(channelName, 0, 0, 0);
	LogiLcdUpdate();
}

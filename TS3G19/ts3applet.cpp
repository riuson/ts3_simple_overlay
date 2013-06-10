// TS3 Applet.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"
#include "ts3applet.h"
#include <LogitechLcd.h>
#include <public_definitions.h>

#define BITMAP_SIZE (307200)
#define CHARS_PRO_LINE (29)
#define NUMBER_MESSAGES (3)

struct message
{
	wchar_t Sender[30];
	wchar_t Message[146];
	anyID TargetMode;
} Messages[NUMBER_MESSAGES];

void ts3applet_setBackground()
{
	BYTE colorBitmap[BITMAP_SIZE];

	for(int i = 0; i < BITMAP_SIZE; i++)
	{
		colorBitmap[i] = 245;
	}

	LogiLcdColorSetBackground(colorBitmap);
}

void ts3applet_init()
{
	LogiLcdInit(L"TS3 Applet", LOGI_LCD_TYPE_COLOR);
	ts3applet_setBackground();
	LogiLcdColorSetTitle(L"TeamSpeak 3", 0, 0, 0);
	LogiLcdUpdate();

	for(int i = 0; i < NUMBER_MESSAGES; i++)
	{
		Messages[i].Sender[29] = L'\0';
		Messages[i].Message[145] = L'\0';
	}
}

void ts3applet_shutdown()
{
	LogiLcdShutdown();
}

void ts3applet_newMessage(wchar_t* sender, wchar_t* message, anyID TargetMode)
{
	static short index = NUMBER_MESSAGES - 1;
	int display;

	if(index == NUMBER_MESSAGES - 1)
		index = 0;
	else
		index++;

	display = index;

	wcsncpy(Messages[index].Sender, sender, 29);
	wcsncpy(Messages[index].Message, message, 145);

	for(int i = 2; i >= 0; i--)
	{
		LogiLcdColorSetText(2 * i + 2, Messages[display].Sender, 0, 0, 0);
		LogiLcdColorSetText(2 * i + 3, Messages[display].Message, 0, 0, 0);

		if(display == 0)
			display = NUMBER_MESSAGES - 1;
		else
			display--;
	}

	LogiLcdUpdate();
}

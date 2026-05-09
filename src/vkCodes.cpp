// Modified vkCodes.c --> vkCodes.cpp from https://github.com/awakecoding/Win32Keyboard/tree/master

#include "vkCodes.h"

struct _VIRTUAL_KEY_CODE
{
	DWORD code; /* Windows Virtual Key Code */
	const char* name; /* Virtual Key Code Name */
};
typedef struct _VIRTUAL_KEY_CODE VIRTUAL_KEY_CODE;

static const VIRTUAL_KEY_CODE VIRTUAL_KEY_CODE_TABLE[256] =
{
    { 0, "" },
    { VK_LBUTTON, " LMB " },
    { VK_RBUTTON, " RMB " },
    { VK_MBUTTON, " MMB " },
    { VK_BACK, " BACKSPACE " },
    { VK_TAB, " TAB " },
    { VK_RETURN, " ENTER " },
    { VK_SHIFT, " SHIFT " },
    { VK_CONTROL, " CTRL " },
    { VK_MENU, " ALT " },
    { VK_PAUSE, " PAUSE " },
    { VK_CAPITAL, " CAPSLOCK " },
    { VK_ESCAPE, " ESCAPE " },
    { VK_SPACE, " SPACE " },
    { VK_PRIOR, " PAGEUP " },
    { VK_NEXT, " PAGEDOWN " },
    { VK_END, " END " },
    { VK_HOME, " HOME " },
    { VK_LEFT, " LEFT " },
    { VK_UP, " UP " },
    { VK_RIGHT, " RIGHT " },
    { VK_DOWN, " DOWN " },
    { VK_SELECT, " SELECT " },
    { VK_PRINT, " PRINT " },
    { VK_EXECUTE, " EXECUTE " },
    { VK_SNAPSHOT, " PRINTSCREEN " },
    { VK_INSERT, " INSERT " },
    { VK_DELETE, " DELETE " },
    { VK_HELP, " HELP " },
    { VK_LWIN, " LWIN " },
    { VK_RWIN, " RWIN " },
    { VK_APPS, " MENU " },
    { VK_SLEEP, " SLEEP " },

    /* Numpad keys */
    { VK_MULTIPLY, " NUM* " },
    { VK_ADD, " NUM+ " },
    { VK_SEPARATOR, " NUMSEP " },
    { VK_SUBTRACT, " NUM- " },
    { VK_DECIMAL, " NUM. " },
    { VK_DIVIDE, " NUM/ " },

    /* Function keys */
    { VK_F1, " F1 " },
    { VK_F2, " F2 " },
    { VK_F3, " F3 " },
    { VK_F4, " F4 " },
    { VK_F5, " F5 " },
    { VK_F6, " F6 " },
    { VK_F7, " F7 " },
    { VK_F8, " F8 " },
    { VK_F9, " F9 " },
    { VK_F10, " F10 " },
    { VK_F11, " F11 " },
    { VK_F12, " F12 " },

    /* Lock keys */
    { VK_NUMLOCK, " NUMLOCK " },
    { VK_SCROLL, " SCROLLLOCK " },

    /* Individual shift/control/alt */
    { VK_LSHIFT, " LSHIFT " },
    { VK_RSHIFT, " RSHIFT " },
    { VK_LCONTROL, " LCTRL " },
    { VK_RCONTROL, " RCTRL " },
    { VK_LMENU, " LALT " },
    { VK_RMENU, " RALT " },

    /* Media keys */
    { VK_VOLUME_MUTE, " VOL_MUTE " },
    { VK_VOLUME_DOWN, " VOL_DOWN " },
    { VK_VOLUME_UP, " VOL_UP " },
    { VK_MEDIA_NEXT_TRACK, " MEDIA_NEXT " },
    { VK_MEDIA_PREV_TRACK, " MEDIA_PREV " },
    { VK_MEDIA_STOP, " MEDIA_STOP " },
    { VK_MEDIA_PLAY_PAUSE, " MEDIA_PLAY " },

    /* Browser keys */
    { VK_BROWSER_BACK, " BROWSER_BACK " },
    { VK_BROWSER_FORWARD, " BROWSER_FORWARD " },
    { VK_BROWSER_REFRESH, " BROWSER_REFRESH " },
    { VK_BROWSER_STOP, " BROWSER_STOP " },
    { VK_BROWSER_SEARCH, " BROWSER_SEARCH " },
    { VK_BROWSER_FAVORITES, " BROWSER_FAVORITES " },
    { VK_BROWSER_HOME, " BROWSER_HOME " },

    /* OEM keys (punctuation/symbols on some layouts) */
    { VK_OEM_1, " ;: " },
    { VK_OEM_PLUS, " =+ " },
    { VK_OEM_COMMA, " ,< " },
    { VK_OEM_MINUS, " -_ " },
    { VK_OEM_PERIOD, " .> " },
    { VK_OEM_2, " /? " },
    { VK_OEM_3, " `~ " },
    { VK_OEM_4, " [{ " },
    { VK_OEM_5, " \\| " },
    { VK_OEM_6, " ]} " },
    { VK_OEM_7, " '\" " },
    { VK_OEM_8, " OEM8 " },

    /* End filler */
    { 0, "" }
};

char* keyboard_get_virtual_key_code_name(DWORD vkcode)
{
	char* vkname;

	if (vkcode >= 0xFF)
		return NULL;

	vkname = (char*) VIRTUAL_KEY_CODE_TABLE[vkcode].name;

	return vkname;
}

DWORD keyboard_get_virtual_key_code_from_name(const char* vkcode_name)
{
	int i;

	for (i = 0; i < ARRAYSIZE(VIRTUAL_KEY_CODE_TABLE); i++)
	{
		if (VIRTUAL_KEY_CODE_TABLE[i].name)
		{
			if (strcmp(vkcode_name, VIRTUAL_KEY_CODE_TABLE[i].name) == 0)
			{
				return VIRTUAL_KEY_CODE_TABLE[i].code;
			}
		}
	}

	return 1;
}
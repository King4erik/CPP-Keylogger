# C++ Keylogger
A keylogger made using C++ of windows.

For now, it is more of a proof of concept, but it works.

The program is considered as WIN32 to hide the console
The program output will be captured only if you mkdir in "../output/Keys.txt"
or you can change the code yourself.

# Currently what I am working on for this project:
- Learning winsock2.h for networking in C++
- ~~Learn to hide the console window~~ and disguise the program as legit
- Making rootkits in linux to hide the program itself (probably after few months)

# Features (for now):
- Logs keystrokes to keys.txt
- Uses windows API LowLevelKeyboardProc to capture keystrokes

# TODO:
- Send the keystrokes to a remote server
- Make a separate server to see the keystrokes in a gui
- Make it stealthy
- Make the keystrokes more understandable
- Send the window application name being used to the server
- Encrypted communication with the server
- Think more ideas

# References:
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms644985(v=vs.85)
- https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa
- https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-kbdllhookstruct?redirectedfrom=MSDN
- https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
- https://github.com/awakecoding/Win32Keyboard/tree/master

Used CLion to develop this project.

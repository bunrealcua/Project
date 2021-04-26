#ifndef _VISUAL_H_
#define _VISUAL_H_
#include <iostream>
#include <Windows.h>

BOOL WINAPI SetConsoleOutputCP(
	_In_ UINT wCodePageID
);

void SetWindowSize(SHORT width, SHORT height);
void HideScrollbar(BOOL Show);
void DisableCtrButton(bool Close, bool Min, bool Max);
void DisableResizeWindow();
void newScreen();
void SetColor(int backgound_color, int text_color);
void GoTo(SHORT posX, SHORT posY);
void DisableSelection();

#endif
/**	util.cpp
 *	util.h �Լ� ����
 *	������ ��Ʈ
 */
#include "util.h"
#include <Windows.h>
void goto_xy(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x * 2,y });
}
void set_color(short f, short b) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (b << 4) | f);
}
void set_cursor(bool s) {
	CONSOLE_CURSOR_INFO c;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
	c.bVisible = s;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &c);
}
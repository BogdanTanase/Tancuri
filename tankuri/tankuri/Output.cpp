#include "Output.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
Output::Output(Engine& pm) :motor(pm) {
}
static int pictvect[MAXNU][2], npict;
void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor);
}
void Output::init() {
	npict = 0;
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = false;
	lpCursor.dwSize = 1;
	SetConsoleCursorInfo(console, &lpCursor);
	system("cls");
//schimb dimensiune consola
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { SetWindowPos(hwnd, 0, 0, 0, 275, 280, SWP_SHOWWINDOW | SWP_NOMOVE); }

	for (int i = 0; i < motor.getnu(); i++) {
		if (*((char*)motor.getunitpoz(i)->gettip()) != (char)177 && motor.getunitpoz(i) != NULL) {
			pictvect[npict][0] = motor.getunitpoz(i)->getx();
			pictvect[npict][1] = motor.getunitpoz(i)->gety();
			npict++;
		}
	}
	for (int i = 0; i < motor.getnu(); i++) {
		gotoxy(motor.getunitpoz(i)->getx(), motor.getunitpoz(i)->gety());
			cout << *((char*)motor.getunitpoz(i)->gettip());
	}
}
void Output::close() {
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = true;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
	system("cls");
}
void Output::afisare() {
	for (int i = 0; i < npict; i++) {
		gotoxy(pictvect[i][0], pictvect[i][1]);
		cout << " ";
	}
	npict = 0;
	for (int i = 0; i < motor.getnu(); i++) {
		if (*((char*)motor.getunitpoz(i)->gettip()) != (char)177 && motor.getunitpoz(i) != NULL) {
			pictvect[npict][0] = motor.getunitpoz(i)->getx();
			pictvect[npict][1] = motor.getunitpoz(i)->gety();
			npict++;
		}
	}
	for (int i = 0; i < npict; i++) {
		gotoxy(pictvect[i][0], pictvect[i][1]);
		cout << *(char*)motor.getunitxy(pictvect[i][0], pictvect[i][1])->gettip();
	}
}

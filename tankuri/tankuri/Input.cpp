#include "Input.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

//completez cu chestii
void Input::init() {
	cout << "incep";
};
void Input::close() {
	cout << " GAME OVER";
};
char Input::getc() {
	Sleep(100);
	if (_kbhit()) {
		char kbcode = _getch();
		switch (kbcode) {
		case 'a':
			return 'a';
			break;
		case 'd':
			return 'd';
			break;
		case 'w':
			return 'w';
			break;
		case 's':
			return 's';
			break;
		case 'c':
			return 'c';
			break;
		case 'h':
			return 'h';
			break;
		case 'k':
			return 'k';
			break;
		case 'u':
			return 'u';
			break;
		case 'j':
			return 'j';
			break;
		case 'i':
			return 'i';
			break;
		case 'q':
			return 'q';
			break;
		case 27:
			return 27;
			break;
		}
	}
	return '0';
}

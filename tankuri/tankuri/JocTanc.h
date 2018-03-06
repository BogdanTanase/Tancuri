#ifndef JOCTANC_H
#define JOCTANC_H
#include "Engine.h"

class Zid :public Unit {
	static unsigned char nume;

protected:
	void action();
	void behaviour(int);

public:
	Zid(int, int);
	void* gettip();
};


class Bomba :public Unit {
	static unsigned char nume;
	int dirx, diry;                 //-1 0 1

protected:
	void action();
	void behaviour(int);

public:
	Bomba(int, int, int, int);
	void* gettip();
};


class Tanc :public Unit {
	unsigned char nume;
	char stg, dr, sus, jos, foc;
	char pc;

protected:
	void action();
	void behaviour(int);

public:
	static char cc;
	Tanc(char, char, char, char, char, char, int, int);
	void* gettip();
};
#endif

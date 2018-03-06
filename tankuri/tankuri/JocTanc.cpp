#include "JocTanc.h"
#include <iostream>
using namespace std;

void Zid::action() {};

void Zid::behaviour(int a) {};

Zid::Zid(int x, int y) :Unit(x, y) {
}

void* Zid::gettip() {
	return &nume;
}

void Bomba::action() {
	int xn = getx() + dirx;
	int yn = gety() + diry;
	if (motor.validxy(xn, yn) == 0) {
		die();
	}
	else {
		if (motor.getunitxy(xn, yn) == NULL) {
			move(xn, yn);
		}
		else {
			sendmes(1, *motor.getunitxy(xn, yn)); //Kill
			die();
		}
	}
}

void Bomba::behaviour(int a) {
	if (a == 1) {
		die();
	}
}

Bomba::Bomba(int x, int y, int dirx, int diry) :Unit(x, y) {
	this->dirx = dirx;
	this->diry = diry;
}

void* Bomba::gettip() {
	return &nume;
}

void Tanc::action() {
	if (cc == stg) {
		if (motor.validxy(getx() - 1, gety() )==1 && motor.getunitxy(getx() - 1, gety()) == NULL) {
			move(getx()-1, gety() );
		}
		pc = cc;
	}
	if (cc == dr) {
		if (motor.validxy(getx() + 1, gety())==1 && motor.getunitxy(getx() + 1, gety()) == NULL) {
			move(getx()+1, gety() );
		}
		pc = cc;
	}
	if (cc == sus) {
		if (motor.validxy(getx(), gety() - 1)==1 && motor.getunitxy(getx(), gety() - 1) == NULL) {
			move(getx(), gety()-1);
		}
		pc = cc;
	}
	if (cc == jos) {
		if (motor.validxy(getx(), gety() + 1)==1 && motor.getunitxy(getx(), gety() + 1) == NULL) {
			move(getx() , gety() + 1);
		}
		pc = cc;
	}
	if (cc == foc) {
		int bx, by;
		if (pc == stg) {
			bx = getx()-1;
			by = gety();
			if (motor.validxy(bx, by) == 1) {
				if (motor.getunitxy(bx, by) == NULL) {
					Bomba *b = new Bomba(bx, by, -1, 0);
				}
				else {
					sendmes(1, *motor.getunitxy(bx, by));
				}
			}
		}
		if (pc == dr) {
			bx = getx() + 1;
			by = gety();
			if (motor.validxy(bx, by) == 1) {
				if (motor.getunitxy(bx, by) == NULL) {
					Bomba *b = new Bomba(bx, by, 1, 0);
				}
				else {
					sendmes(1, *motor.getunitxy(bx, by));
				}
			}
		}
		if (pc == sus) {
			bx = getx();
			by = gety() -1;
			if (motor.validxy(bx, by) == 1) {
				if (motor.getunitxy(bx, by) == NULL) {
					Bomba *b = new Bomba(bx, by, 0, -1);
				}
				else {
					sendmes(1, *motor.getunitxy(bx, by));
				}
			}
		}
		if (pc == jos) {
			bx = getx();
			by = gety() + 1;
			if (motor.validxy(bx, by) == 1) {
				if (motor.getunitxy(bx, by) == NULL) {
					Bomba *b = new Bomba(bx, by, 0, 1);
				}
				else {
					sendmes(1, *motor.getunitxy(bx, by));
				}
			}
		}
	}
}

void Tanc::behaviour(int a) {
	if (a == 1) { // kill
		die();
	}
}

Tanc::Tanc(char stg, char dr, char sus, char jos, char foc, char nume, int x, int y) :Unit(x, y) {
	this->stg = stg;
	this->dr = dr;
	this->sus = sus;
	this->jos = jos;
	this->foc = foc;
	this->nume = nume;
}

void* Tanc::gettip() {
	return &nume;
}

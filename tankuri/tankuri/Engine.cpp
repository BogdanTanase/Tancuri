#include "Engine.h"
#include <iostream>

using namespace std;
void Engine::init(int nc, int nl) {
	if (nc > MAXNC) {
		cout << "Matrix colum exedded";
		return;
	}
	if (nl > MAXNL) {
		cout << "Matrix lines excedded";
		return;
	}
	else {
		this->nc = nc;
		this->nl = nl;
		this->nu = 0;
		for (int i = 0; i < nc; i++) {       //matrice de NULL
			for (int j = 0; j < nl; j++) {
				unittab[i][j] = NULL;
			}
		}
	}
}
int Engine::getnl() {
	return nl;
}
int Engine::getnc() {
	return nc;
}
int Engine::getnu() {
	return nu;
}
int Engine::validxy(int x, int y) {
	if (x >= 0 && x < nc && y >= 0 && y < nl) {
		return 1;
	}
	return 0;
}
int Engine::validpoz(int p) {
	if (p >= 0 && p < nu) {
		return 1;
	}
	return 0;
}
Unit* Engine::getunitpoz(int p) {
	return univect[p];
}
Unit* Engine::getunitxy(int x, int y) {
	return unittab[x][y];
}
void Engine::next() {
	for (int i = 0; i < nu; i++) {
		univect[i]->action();
	}
	for (int i = 0; i < nu; i++) {
		univect[i]->react();
	}
	for (int i = 0; i < nu; i++) {
		if (univect[i]->alive == 0) {
			unittab[univect[i]->getx()][univect[i]->gety()] = NULL;
			delete univect[i];
			for (int j = i; j < nu ; j++) {
				univect[j] = univect[j + 1];
			}
			nu--;
		}
	}
}
void Unit::react() {
	for (int i = 0; i < nm; i++) {
		if (alive == 1) {
			this->behaviour(message[i]);
		}
	}
	nm = 0;
}
Unit::Unit(int x, int y) {
	this->x = x;
	this->y = y;
	if (motor.validxy(x, y) == 0 || motor.nu == MAXNU) {
		cout << "Nu s-a creat unitatea";
		return;
	}
	nm = 0;
	alive = 1;
	motor.univect[motor.nu] = this;
	motor.nu++;
	motor.unittab[x][y] = this;
	
	//+alt ceva
}

Unit::~Unit() {}

void Unit::die() {
	alive = 0;
}
void Unit::move(int dx, int dy) {
	motor.unittab[dx][dy] = this;
	motor.unittab[x][y] = NULL;
	x = dx;
	y = dy;
}
void Unit::sendmes(int pm, Unit& pu) {
	if (pu.nm == MAXIM) {
		return;
	}
	else {
		pu.message[pu.nm] = pm;
		pu.nm++;
	}
}
int Unit::getx() {
	return x;
}
int Unit::gety() {
	return y;
}

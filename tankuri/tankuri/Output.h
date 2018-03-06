
#ifndef OUTPUT_H
#define OUTPUT_H
#include "JocTanc.h"
class Output {
	Engine& motor;

public:
	Output(Engine& pm);
	void init();
	void close();
	void afisare();
};
#endif

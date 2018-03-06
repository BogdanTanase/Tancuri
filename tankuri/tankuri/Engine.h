#define MAXNC 100
#define MAXNL 100
#define MAXNU 10000
#define MAXIM 10000
#ifndef ENGINE_H
#define ENGINE_H

class Unit;
class Engine {
	friend class Unit;
	Unit* unittab[MAXNC][MAXNL]; // tabla de joc
	Unit* univect[MAXNU];		 // lista unitatilor de pe tabla
	int nc, nl, nu;              // nr : linii , coloane , unitati existente

public:
	void init(int, int);
	int getnl();
	int getnc();
	int getnu();
	int validxy(int, int);		 //test:parametrii reprezinta o valoare valida pe unittab
	int validpoz(int);           //test:e pe unitvec
	Unit* getunitxy(int, int);
	Unit* getunitpoz(int);       //return adr unitatii de pe poz data in unitvec
	void next();                 //zha most important
};

class Unit {
	friend class Engine;
	int alive;                   //initial 1 ca e viu
	int x, y, poz;
	int message[MAXIM];		 //lista cu mesaje provenite de la alte unitati
	int nm;                      //nr mesaje din message
	void react();                //reactia la actiunile altor unitati asupra sa

protected:
	Unit(int, int);              //constructor
	virtual ~Unit();             //destructor
	void die();                  //alive devine 0 nu apeleaza destructor
	void move(int dx, int dy);   //muta unitatea
	void sendmes(int pm, Unit& pu);
	virtual void action() = 0;   //important, ce face unitatea
	virtual void behaviour(int) = 0; //comportament fata de un anumit mesaj

public:
	static Engine motor;
	int getx();
	int gety();
	virtual void* gettip()=0;      //returneaza adresa unde se fla info despre unitate
};
#endif

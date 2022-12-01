#ifndef _CVECARA_H_
#define _CVECARA_H_

#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"

class Cvecara {

public:

	Cvecara() : prvi(nullptr) {}

	Cvecara& dodaj(Buket&);

	Cvecara& prodaj(int);

	Cvecara(const Cvecara&);

	Cvecara(Cvecara&&);

	friend ostream& operator<<(ostream&, Cvecara&);

	~Cvecara();

private:

	void kopiraj(const Cvecara&);

	void premesti(Cvecara&);

	void brisi();

	struct Elem {
		Buket* buket;
		Elem* next = nullptr;
		Elem(Buket& b) : buket(&b) {}
	};

	int zarada = 1000;

	int kolicina = 0;

	Elem* prvi;

};

#endif
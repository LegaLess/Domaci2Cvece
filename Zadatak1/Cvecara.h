#pragma once
#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"

class Cvecara {

public:

	Cvecara& dodaj(Buket&);

	Cvecara& prodaj(int);

	friend ostream& operator<<(ostream&, Cvecara&);

	~Cvecara() {
		Elem* tek = prvi;
		Elem* pr = tek;
		while (tek) {
			pr = tek;
			tek = tek->next;
			delete pr;
		}
	}

private:

	struct Elem {
		Buket& buket;
		Elem* next = nullptr;
		Elem(Buket& b) : buket(b) {}
	};

	int zarada = 1000;

	Elem* prvi;

};

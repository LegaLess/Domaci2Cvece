#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"

Buket& Buket::dodaj(Cvet& c)
{
	Elem* novi = new Elem(c);

	if (prvi) {
		novi->next = prvi;
		prvi = novi;
	}
	else {
		prvi = novi;
	}

	return *this;
}

int Buket::zarada() {
	int s = 0;
	Elem* tek = prvi;

	while (tek) {
		s += tek->cvet->zarada();
		tek = tek->next;
	}
	
	return s;
}

int Buket::prodCena() const
{
	int s = 0;
	Elem* tek = prvi;

	while (tek) {
		s += tek->cvet->get_cenaP();
		tek = tek->next;
	}

	return s;
}

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

Buket::Buket(const Buket& b1)
{



}

int Buket::zarada() const 
{
	int s = 0;
	Elem* tek = prvi;

	while (tek) {
		s += tek->cvet->zarada();
		tek = tek->next;
	}
	
	return s;
}

int Buket::nabavna() const 
{
	int s = 0;
	Elem* tek = prvi;

	while (tek) {
		s += tek->cvet->get_cenaN();
		tek = tek->next;
	}

	return s;
}

int Buket::prodajna() const
{
	int s = 0;
	Elem* tek = prvi;

	while (tek) {
		s += tek->cvet->get_cenaP();
		tek = tek->next;
	}

	return s;
}

float Buket::procenatZar() const
{
	float sP = 0;
	float sN = 0;
	Elem* tek = prvi;


	while (tek) {
		sP += tek->cvet->get_cenaP();
		sN += tek->cvet->get_cenaN();
		tek = tek->next;
	}

	return sN / sP;
}


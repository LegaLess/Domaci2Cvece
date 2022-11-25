#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"

Cvecara& Cvecara::dodaj(Buket& b)
{
	if (b.procenatZar() > 0.2) {
		Elem* novi = new Elem(b);

		if (prvi) {
			novi->next = prvi;
			prvi = novi;
		}
		else {
			prvi = novi;
		}

		zarada -= novi->buket.nabavna();

	}
	return *this;
}

Cvecara& Cvecara::prodaj(int rb)
{
	int i = 1;
	Elem* tek = prvi;
	Elem* pret = tek;

	while (i != rb) {
		pret = tek;
		tek = tek->next;
		i++;
	}

	zarada += tek->buket.prodajna();

	pret->next = tek->next;

	if (i == 1) {
		prvi = tek->next;
	}

	delete tek;

	return *this;
}

ostream& operator<<(ostream& it, Cvecara& c)
{
	it << "zarada=" << c.zarada << "RSD" << endl;
	
	Cvecara::Elem* tek = c.prvi;

	while (tek) {
		it << tek->buket << endl;
		tek = tek->next;
	}

	return it;
}

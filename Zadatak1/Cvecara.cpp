#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"

void Cvecara::kopiraj(const Cvecara& c) {
	Elem* tek = c.prvi;
	while (tek) {
		this->dodaj(*tek->buket);
		tek = tek->next;
	}
}

void Cvecara::premesti(Cvecara& c) {
	this->prvi = c.prvi;
	c.prvi = nullptr;
}

void Cvecara::brisi() {
	Elem* tek;
	while (tek = prvi) {
		prvi = prvi->next;
		delete tek;
	}
}

Cvecara::Cvecara(const Cvecara& c) {
	kopiraj(c);
}

Cvecara::Cvecara(Cvecara&& c) {
	premesti(c);
}

Cvecara::~Cvecara() {
	brisi();
}

Cvecara& Cvecara::dodaj(Buket& b)
{
	Elem* novi = new Elem(b);
	if (b.prodajna() > b.nabavna() * 1.2) {
		if (!prvi || prvi->buket->prodajna() >= novi->buket->prodajna()) {
			novi->next = prvi;
			prvi = novi;
			kolicina++;
		}
		else {
			Elem* tek = prvi;

			while (tek->next && tek->next->buket->prodajna() < novi->buket->prodajna()) {
				tek = tek->next;
			}
			novi->next = tek->next;
			tek->next = novi;
			kolicina++;
		}
	}

	return *this;
}

Cvecara& Cvecara::prodaj(int rb)
{
	int i = 1;
	Elem* tek = prvi;
	Elem* pret = tek;

	if (rb > kolicina) {
		return *this;
	}

	while (i != rb) {
		pret = tek;
		tek = tek->next;
		i++;
	}

	zarada += tek->buket->prodajna();

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
		it << *tek->buket << endl;
		tek = tek->next;
	}

	return it;
}

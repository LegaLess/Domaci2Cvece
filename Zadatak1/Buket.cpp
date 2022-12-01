#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"

Buket& Buket::dodaj(Cvet& c)
{
	Elem* novi = new Elem(c);

	if (prvi) {
		novi->next = prvi;
	}

	prvi = novi;
	return *this;
}

Buket& Buket::dodajJ(Cvet& c) {
	Elem* novi = new Elem(c);

	if (prviJ) {
		novi->next = prviJ;
	}

	prviJ = novi;
	return *this;
}

void Buket::brisi() {
	Elem* tek;
	while (tek = prvi) {
		prvi = prvi->next;
		delete tek;
	}
	prvi = nullptr;
}

void Buket::kopiraj(const Buket& b) {
	Elem* tek = b.prvi;

	while (tek) {
		this->dodaj(*tek->cvet);
		tek = tek->next;
	}
}

void Buket::premesti(Buket& b) {
	this->prvi = b.prvi;
	b.prvi = nullptr;
}

Buket::Buket(const Buket& b) {
	kopiraj(b);
}

Buket::Buket(Buket&& b) {
	if (this != &b) {
		brisi();
		premesti(b);
	}
}

Buket::~Buket() {
	brisi();
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

ostream& operator<<(ostream& it, Buket& b) {
	Buket::Elem* tek = b.prvi;
	Buket::Elem* tekJ = b.prviJ;

	while (tek) {
		while (tekJ) {
			if (tekJ->cvet->get_naziv() == tek->cvet->get_naziv()) break;
			tekJ = tekJ->next;
		}
		if (!tekJ) {
			b.dodajJ(*tek->cvet);
		}
		tekJ = b.prviJ;
		tek = tek->next;
	}

	cout << "(";

	while (tekJ) {
		if (tekJ->next) {
			it << tekJ->cvet->get_naziv() + ",";
		}
		else {
			it << tekJ->cvet->get_naziv() + ") " << b.prodajna() << "RSD";
		}
		tekJ = tekJ->next;
	}
	return it;
}

bool operator>(const Buket& b1, const Buket& b2) { return b1.prodajna() > b2.prodajna(); }


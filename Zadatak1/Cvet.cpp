#include "Cvet.h"

#include <iostream>
#include <string>

using namespace std;

Cvet::Cvet(string naziv, int cn, int cp)
{
	this->naziv = naziv;
	cenaN = cn;
	cenaP = cp;
}

string Cvet::get_naziv() const { return this->naziv; }

int Cvet::zarada() const { return cenaP - cenaN; }

int Cvet::get_cenaN() const { return cenaN; }

int Cvet::get_cenaP() const { return cenaP; }

bool operator==(const Cvet& c1, const Cvet& c2) { return c1.naziv == c2.naziv; }

ostream& operator<<(ostream& it, const Cvet& c) { return it << c.get_naziv(); }
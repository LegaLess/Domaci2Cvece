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

string Cvet::get_naziv() { return this->naziv; }

int Cvet::zarada() { return cenaP - cenaN; }

int Cvet::get_cenaN() { return cenaN; }

int Cvet::get_cenaP() { return cenaP; }
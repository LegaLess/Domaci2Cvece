#include "Cvet.h"

#include <iostream>
#include <string>

using namespace std;

Cvet::Cvet(string naziv, int cn, int cp)
{
	this->naziv = naziv;
	this->cenaN = cn;
	this->cenaP = cp;
}

string Cvet::get_naziv() { return this->naziv; }

int Cvet::zarada() { return this->cenaP - this->cenaN; }

int Cvet::get_cenaN() { return this->cenaN; }

int Cvet::get_cenaP() { return this->cenaP; }
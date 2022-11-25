#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cvet {

private:
	string naziv;
	int cenaN;
	int cenaP;

public:

	friend bool operator==(const Cvet& c1, const Cvet& c2) {
		return c1.naziv == c2.naziv;
	}

	friend ostream& operator<<(ostream& it, const Cvet& c) {
		return it << c.naziv;
	}

	Cvet(string, int, int);
	string get_naziv();
	int zarada();
	int get_cenaN();
	int get_cenaP();

};



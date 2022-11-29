#pragma once

#include <iostream>
#include <string>

using namespace std;

class Cvet {

public:

	friend bool operator==(const Cvet&, const Cvet&);

	friend ostream& operator<<(ostream&, const Cvet&);

	Cvet(string, int, int);
	string get_naziv() const;
	int zarada() const;
	int get_cenaN() const;
	int get_cenaP() const;


private:
	string naziv;
	int cenaN;
	int cenaP;

};



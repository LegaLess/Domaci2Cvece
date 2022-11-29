#ifndef _BUKET_H_
#define _BUKET_H_

#include <iostream>
#include <string>
#include "Cvet.h"

class Buket {

public:

	Buket& dodaj(const Cvet&);

	Buket() : prvi(nullptr), prviJ(nullptr) {}

	Buket(const Buket&);

	Buket(Buket&&);

	int zarada() const;

	int nabavna() const;

	int prodajna() const;

	friend ostream& operator<<(ostream&, Buket&);

	friend bool operator>(Buket&, Buket&);
	
	~Buket();
	

private:

	Buket& dodajJ(const Cvet&);

	float procenatZar() const;

	void kopiraj(const Buket&);

	void premesti(Buket&);

	void brisi();

	struct Elem {
		const Cvet cvet;
		Elem* next = nullptr;
		Elem(const Cvet& c) : cvet(c){}
	};

	Elem* prvi;

	Elem* prviJ;

};

#endif
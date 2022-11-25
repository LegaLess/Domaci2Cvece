#pragma once
#include <iostream>
#include <string>
#include "Cvet.h"

class Buket {

public:

	Buket& dodaj(Cvet&);

	int zarada() const;

	int nabavna() const;

	int prodajna() const;

	float procenatZar() const;

	friend ostream& operator<<(ostream& it, const Buket& b) {
		Elem* tek = b.prvi;

		while (tek) {
			if (tek->next) {
				it << tek->cvet->get_naziv() + ",";
			}
			else {
				it << tek->cvet->get_naziv() + " " << b.prodajna() << "RSD";
			}
			tek = tek->next;
		}
		return it;
	}

	friend bool operator>(Buket& b1, Buket& b2) {
		return b1.prodajna() > b2.prodajna();
	}
	
	~Buket() {
		Elem* tek = prvi;
		Elem* pr = tek;
		while (tek) {
			pr = tek;
			tek = tek->next;
			delete pr;
		}
	}
	

private:

	struct Elem {
		Cvet* cvet;
		Elem* next = nullptr;
		Elem(Cvet& c) : cvet(&c){}
	};

	Elem* prvi;

};

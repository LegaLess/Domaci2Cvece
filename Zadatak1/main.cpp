#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"

using namespace std;

int main() {

	Cvet c1("plavi", 500, 800);
	Cvet c2("crveni", 200, 400);
	Cvet c3("zeleni", 250, 700);
	Cvet c4("zuti", 900, 1800);
	Cvet c5("ljubicasti", 800, 1000);

	Buket b1;
	b1.dodaj(c1).dodaj(c2).dodaj(c3).dodaj(c4).dodaj(c5);

	Buket b2;
	b2.dodaj(c2).dodaj(c5);

	Buket b3;
	b3.dodaj(c4).dodaj(c4);

	Buket b4;
	b4.dodaj(c4).dodaj(c5).dodaj(c3);

	Cvecara cvecara;

	cvecara.dodaj(b1);
	
	cout << cvecara << endl;

	cvecara.dodaj(b2);

	cout << cvecara << endl;

	cvecara.dodaj(b3);

	cout << cvecara << endl;

	cvecara.dodaj(b4);

	cout << cvecara << endl;

	cvecara.prodaj(1);

	cout << cvecara << endl;

	return 0;
}
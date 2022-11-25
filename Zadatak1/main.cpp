#include <iostream>
#include <string>
#include "Cvet.h"
#include "Buket.h"

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
	b2.dodaj(c2);

	cout << b1 << endl;

	if(b1 > b2) cout << 1;


	return 0;
}
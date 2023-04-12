#include <iostream>
#include "Zamowienie.h"
#include "Silnik.h"
#include "Kolo.h"
#include "DodatkoweWyposazenie.h"
#include "Samochod.h"
#include "FabrykaSamochodow.h"
using namespace std;
int Samochod::liczbaSamochodow = 0;
int main(int argc, char** argv) {
	string tabDodWyp[3];
	tabDodWyp[0] = "kilmatyzacja 3-strefowa";
	tabDodWyp[1] = "radar - City Safe";
	tabDodWyp[2] = "podgrzewana tylna kanapa";
	Zamowienie* zamowienie1 = new Zamowienie("Volvo", "V60", 1995, 5, 181, 17, tabDodWyp);
	tabDodWyp[0] = "";
	tabDodWyp[1] = "";
	tabDodWyp[2] = "";
	Zamowienie* zamowienie2 = new Zamowienie("Ford", "Mondeo", 1994, 4, 140, 16, tabDodWyp);
	FabrykaSamochodow* Detroit = new FabrykaSamochodow();
	Samochod* wyprodukowanySam1 = NULL;
	wyprodukowanySam1 = Detroit->wyprodukujSamochod(zamowienie1);
	if (wyprodukowanySam1 != NULL)
	{
		Detroit->dodajWyposazenie(wyprodukowanySam1, zamowienie1);
		cout << "Fabryka w Detroit wyprodukowala:\n";
		wyprodukowanySam1->wyswietlSpecyfikacje();
	}
	Samochod* wyprodukowanySam2 = NULL;
	wyprodukowanySam2 = Detroit->wyprodukujSamochod(zamowienie2);
	if (wyprodukowanySam2 != NULL)
	{
		Detroit->dodajWyposazenie(wyprodukowanySam2, zamowienie2);
		cout << "Fabryka w Detroit wyprodukowala:\n";
		wyprodukowanySam2->wyswietlSpecyfikacje();
	}
	zamowienie2->tabDodatkoweWyposazenie[0] = "kilmatyzacja 2-strefowa";
	Samochod* wyprodukowanySam3 = NULL;
	wyprodukowanySam3 = Detroit->wyprodukujSamochod(zamowienie2);
	if (wyprodukowanySam3 != NULL)
	{
		Detroit->dodajWyposazenie(wyprodukowanySam3, zamowienie2);
		cout << "Fabryka w Detroit wyprodukowala:\n";
		wyprodukowanySam3->wyswietlSpecyfikacje();
	}
	cout << "Fabryka w Detroit wyprodukowala dzisiaj: " << Samochod::getLiczbaSamochodow() << " samochody, to byl pracowity dzien!" << endl;
delete Detroit, zamowienie1, zamowienie2;
	cout << endl;
	delete wyprodukowanySam1;
	cout << endl;
	delete wyprodukowanySam2;
	cout << endl;
	delete wyprodukowanySam3;
	return 0;

}

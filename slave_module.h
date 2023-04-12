#ifndef SLAVE_MODULE_H
#define SLAVE_MODULE_H
#include <iostream>
using namespace std;
class Zamowienie
{
	friend class FabrykaSamochodow;
private:
	string markaAuta;
	string modelAuta;
	int pojemnoscSilnika;
	int liczbaCylindrowSilnika;
	int mocSilnika;
	int rozmiarKol;
public:
	string tabDodatkoweWyposazenie[3];
	Zamowienie(string markaAuta, string modelAuta, int pojemnoscSilnika, 
	int liczbaCylindrowSilnika, int mocSilnika, int rozmiarKol, string* tabDodatkoweWyposazenie);
	//string* getDodatkoweWyposazenieTab();
};
class Silnik
{
	friend class FabrykaSamochodow;
private:
	int pojemnosc;
	int liczbaCylindrow;
	int moc;
public:
	Silnik(int pojemnosc, int liczbaCylindrow, int moc);
	~Silnik();
	int getPojemnnosc();
	int getLiczbaCylindrow();
	int getMoc();
};
class Kolo
{
	friend class FabrykaSamochodow;
private:
	int rozmiar;
public:
	Kolo(int rozmiar);
	~Kolo();
	int getRozmiar();
};
class DodatkoweWyposazenie
{
private:
	string nazwa;
public:
	DodatkoweWyposazenie(string rozmiar);
	~DodatkoweWyposazenie();
	string getNazwa();
};
class Samochod
{
	friend class FabrykaSamochodow;
private:
	string marka;
	string model;
	Silnik* silnik;
	Kolo* kola[4];	
	DodatkoweWyposazenie* wyposazenie[3];
	static int liczbaSamochodow;
	
public:
	Samochod(string marka, string model, int pojemnosc, int liczbaCylindrow, int moc, int rozmiarKol);
	~Samochod();
	void wyswietlSpecyfikacje();
	static int getLiczbaSamochodow();
};
class FabrykaSamochodow
{
public:
	void dodajWyposazenie(Samochod* samochod, Zamowienie* zamowienie);
	Samochod* wyprodukujSamochod(Zamowienie* zamowienie);
};

#endif

#include <iostream>

#include "Zamowienie.h"
#include "Silnik.h"
#include "Kolo.h"
#include "DodatkoweWyposazenie.h"
#include "Samochod.h"
#include "FabrykaSamochodow.h"

int Kolo::getRozmiar() {
	return this->rozmiar;
}
Kolo::Kolo(int rozmiar, int szerokosc) {
	this->szerokosc = szerokosc;
	this->rozmiar = rozmiar;
}
Kolo::~Kolo()
{
	cout << "Zniszczono kolo!" << endl;
}

int Silnik::getLiczbaCylindrow() {
	return this->liczbaCylindrow;
}
int Silnik::getMoc() {
	return this->moc;
}
int Silnik::getPojemnnosc() {
	return this->pojemnosc;
}
Silnik::Silnik(int pojemnosc, int liczbaCylindrow, int moc) {
	this->pojemnosc = pojemnosc;
	this->liczbaCylindrow = liczbaCylindrow;
	this->moc = moc;
}
Silnik::~Silnik()
{
	cout << "Zniszczono silnik!" << endl;
}

string DodatkoweWyposazenie::getNazwa() {
	return this->nazwa;
}
DodatkoweWyposazenie::DodatkoweWyposazenie(string nazwa) {
	this->nazwa = nazwa; 
}
DodatkoweWyposazenie::~DodatkoweWyposazenie()
{
	cout << "Zniszczono dodatkowe wyposazenie!" << endl;
}

Zamowienie::Zamowienie(string markaAuta, string modelAuta, int pojemnoscSilnika, 
	int liczbaCylindrowSilnika, int mocSilnika, int rozmiarKol, string* tabDodatkoweWyposazenie) {
	this->markaAuta = markaAuta; 
	this->modelAuta = modelAuta; 
	this->pojemnoscSilnika = pojemnoscSilnika; 
	this->liczbaCylindrowSilnika = liczbaCylindrowSilnika; 
	this->mocSilnika = mocSilnika; 
	this->rozmiarKol = rozmiarKol; 
	int i;
	for (i = 0; i < 3; i++) {
		this->tabDodatkoweWyposazenie[i] = *(tabDodatkoweWyposazenie + i);
	}
}
int Samochod::getLiczbaSamochodow() {
	return Samochod::liczbaSamochodow;
}
void Samochod::wyswietlSpecyfikacje() {
	cout<<"Pojazd: "<<this->marka<<" "<<this->model<<endl;
	cout<<"Silnik: "<<this->silnik->getPojemnnosc()<<"cm^3, "<<this->silnik->getLiczbaCylindrow()<<" cylindrow , "<<this->silnik->getMoc()<<"KM"<<endl;
	cout<<"Kola: "<<this->kola[0]->getRozmiar()<<" cali"<<endl;
	cout<<"Dodatkowe wyposazenie:"<<endl;
	int i, flag = 0;
	for (i = 0; i < 3; i++) {
		if (this->wyposazenie[i]->getNazwa() != "") {
			cout<<this->wyposazenie[i]->getNazwa()<<endl;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout<<"Brak dodatkowego wyposazenia"<<endl;
	}
}
Samochod::Samochod(string marka, string model, int pojemnosc, int liczbaCylindrow, int moc, int rozmiarKol)
	: silnik(new Silnik(pojemnosc, liczbaCylindrow, moc)) {
	int i;
	for (i = 0; i < 4 ; i++) {
		this->kola[i] = new Kolo(rozmiarKol);
	}
	
	Samochod::liczbaSamochodow++;
	this->marka = marka;
	this->model = model;
}
Samochod::~Samochod() {
	Samochod::liczbaSamochodow--;
	
	delete this->silnik;
	int i;
	for (i = 0; i < 4; i++) {
		if (this->kola[i] != NULL) {
			delete this->kola[i];
		}
		
	}
	for (i = 0; i < 3; i++) {
		if (this->wyposazenie[i] != NULL) {
			delete this->wyposazenie[i];
		}
	}
	cout<<"Zniszczono samochod" <<endl;
}
Samochod* FabrykaSamochodow::wyprodukujSamochod(Zamowienie* zamowienie) {
	Samochod* sam1 = new Samochod(zamowienie->markaAuta, zamowienie->modelAuta, zamowienie->pojemnoscSilnika, 
	zamowienie->liczbaCylindrowSilnika, zamowienie->mocSilnika, zamowienie->rozmiarKol);
	int i;
	for (i = 0; i < 3 ; i++) {
			sam1->wyposazenie[i] = new DodatkoweWyposazenie(zamowienie->tabDodatkoweWyposazenie[i]);
	}
	return sam1;
}
void FabrykaSamochodow::dodajWyposazenie(Samochod* samochod, Zamowienie* zamowienie) {
	int i;
	for (i = 0; i < 3 ; i++) {
		if (samochod->wyposazenie[i] == NULL) {
			samochod->wyposazenie[i] = new DodatkoweWyposazenie(zamowienie->tabDodatkoweWyposazenie[i]);
		}
	}
}

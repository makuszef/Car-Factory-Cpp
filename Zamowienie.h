
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

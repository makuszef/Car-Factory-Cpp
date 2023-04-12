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

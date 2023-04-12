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

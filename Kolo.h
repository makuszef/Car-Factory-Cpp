class Kolo
{
	friend class FabrykaSamochodow;
private:
	int rozmiar;
	int szerokosc;
public:
	Kolo(int rozmiar, int szerokosc);
	~Kolo();
	int getRozmiar();
};

#ifndef PLANSZA
#define PLANSZA

class Plansza {
private:
// 2^0 + 2^1 + 2^2 + 2^3
	const int MASKA_BITOwA;
	const int KROK;
	const int LICZBA_POL;
	
	long long plansza;
public:
	void przesuwaKlocek(int klocekWiersz, int klocekKolumna, int zeroWiersz, int zeroKolumna);
	int wypiszElement(int, int);
	int wypiszElement(int);
	void zapiszElement(int, int, int);
	void zapiszElement(int, int);
	
	void operator= (const Plansza &);
	
	Plansza();
	Plansza(const Plansza &);
	Plansza(long long);
	// poniższy konstruktor przyjmuje tablice intwo
	// zakladamy jednak z gory, ze ta tablica ma 15
	// elementow
	Plansza(int *);
};

#endif
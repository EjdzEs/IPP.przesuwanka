#include "plansza.hxx"

void Plansza::przesuwaKlocek(int klocekWiersz, int klocekKolumna, int zeroWiersz, int zeroKolumna)
{
	zapiszElement(zeroWiersz, zeroKolumna, wypiszElement(klocekWiersz, klocekKolumna));
	
	zapiszElement(klocekWiersz, klocekKolumna, 0);
}

int Plansza::wypiszElement(int wiersz, int kolumna)
{
	return wypiszElement(wiersz * LICZBA_POL + kolumna);
}

int Plansza::wypiszElement(int n)
{
	long long wartosc = plansza;
	
	for (int i = 0; i < n; ++i) {
		wartosc = wartosc >> KROK;
	}
	
	return (wartosc & MASKA_BITOwA);
}

void Plansza::zapiszElement(int n, int wartosc)
{
	long long maska = MASKA_BITOwA;
	
	for (int i = 0; i < n; ++i) {
		wartosc = wartosc << KROK;
		maska = maska << KROK;
	}

	maska = ~maska;
	plansza = (plansza & maska) | wartosc;
}

void Plansza::zapiszElement(int wiersz, int kolumna, int wartosc)
{
	zapiszElement(wiersz * LICZBA_POL + kolumna, wartosc);
}

void Plansza::operator=(const Plansza& obiekt)
{
	this->plansza = obiekt.plansza;
}

Plansza::Plansza() : MASKA_BITOwA(1 + 2 + 2*2 + 2*2*2), KROK(4), LICZBA_POL(4) {
}

Plansza::Plansza(const Plansza &obiekt) : MASKA_BITOwA(1 + 2 + 2*2 + 2*2*2), KROK(4), LICZBA_POL(4){
	this->plansza = obiekt.plansza;
}

Plansza::Plansza(long long plansza) : MASKA_BITOwA(1 + 2 + 2*2 + 2*2*2), KROK(4), LICZBA_POL(4)
{
	this->plansza = plansza;
}

Plansza::Plansza(int *tab) : MASKA_BITOwA(1 + 2 + 2*2 + 2*2*2), KROK(4), LICZBA_POL(4)
{	
    plansza = 0;
	for (int i = 0; i < 15; ++i) {
		zapiszElement(i, tab[i]);
	}
}

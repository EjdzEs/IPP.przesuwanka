#include "permutacje.hxx"
#include <cstdlib>
#include <ctime>

int Permutacje::next(bool tab[])
{
	int i = 0;
	
	while ((tab[i] == true) && (i < n)) {
		++i;
	}
	
	i = (i == n) ? (-1) : i;
	
	return i;
}

bool Permutacje::czyParzystyCykl(int x[], int i, bool tab[])
{
	int pierwszy = i;
	int licznik = 1;
	
	tab[i] = true;

	while (x[i] - 1 != pierwszy) {

		tab[i] = true;

		i = x[i] - 1;
		++licznik;
	}
	tab[i] = true;
	
	return ((licznik % 2) == 0);
}

bool Permutacje::czyParzystaPermutacja(int x[])
{
	int liczbaParzystychCykli = 0;
	bool tab[n];
	
	for (int i = 0; i < n; ++i) {
		tab[i] = false;
	}
	
	int i = 0;
	while (i != -1) {
		if (czyParzystyCykl(x, i, tab)) {
			liczbaParzystychCykli++;
		}

		i = next(tab);
	}
	
	return ((liczbaParzystychCykli % 2) == 0);
}

bool Permutacje::dubel(int liczba, int tab[], int index)
{
	int i = 0;
	
	while ((i < index) && (tab[i] != liczba)) {
		++i;
	}
	
	return !(i == index);
}

int* Permutacje::losujePermutacje()
{
	int *tab = new int[n];
	
	for (int i = 0; i < n; ++i) {
		int propozycja = 1 + (rand() % n);
		
		while (dubel(propozycja, tab, i)) {
			propozycja = 1 + (rand() % n);
		}
		
		tab[i] = propozycja;
	}
	
	return tab;
}

int* Permutacje::losujeParzystaPermutacje()
{
	int *permutacja = losujePermutacje();
	
	while (!czyParzystaPermutacja(permutacja)) {
		permutacja = losujePermutacje();
	}
	
	return permutacja;
}

Permutacje::Permutacje(int n)
{
	srand(time(NULL));
	this->n = n;
}

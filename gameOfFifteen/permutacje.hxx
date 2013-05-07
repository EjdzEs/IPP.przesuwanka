#ifndef PERMUTACJE
#define PERMUTACJE

class Permutacje {
private:
	int n;
	
	int next(bool []);
	bool czyParzystyCykl(int [], int i, bool []);
	bool czyParzystaPermutacja(int []);
	bool dubel(int, int [], int);
	int * losujePermutacje();
	
public:
	int * losujeParzystaPermutacje();
	Permutacje(int);
};

#endif
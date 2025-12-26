#include <iostream>

using namespace std;

int BB(int ini, int fin);

int main() {
	int ini, fin;
	cin >> ini >> fin;

	while (ini) {
		cout << BB(ini, fin) << endl;
		cin >> ini >> fin;
	}

	return 0;
}

int BB(int ini, int fin) {
	
	while (ini < fin){
		int m = (ini + fin) / 2;

		if (posible(ini, m, fin))
			ini = m + 1;
		else
			fin = m;
	}

	return ini;
}

bool posible(int ini, int m, int fin) {


}


int numDigs(int n) {
	if (n < 10)
		return n + 1;

	int dig = n % 10;
	int raiz = n / 10;

	return (numDigs(raiz) * 10) + ();
}
#include <iostream>
using namespace std;

const int MAX = 200000;

void VA(int h1[], int h2[], int t, int i, int j, int solP, int& mayor);

int main() {
	int* h1 = new int[MAX];
	int *h2 = new int[MAX];
	int n, m, t, mayor;

	while (cin) {
		cin >> n >> m >> t;
		mayor = 0;
		for (int i = 0; i < n; ++i) cin >> h1[i];
		for (int i = 0; i < m; ++i) cin >> h2[i];

		VA(h1, h2, t, n -1, m- 1, 0, mayor);

		cout << mayor << endl;
	}

	delete[] h1;
	delete[] h2;
	return 0;
}

void VA(
	//Datos del problema
	int h1[], int h2[], int t,

	//SolParcial
	int i,
	int j,
	int solP,

	// maxSol
	int& mayor
) {

	//Caso base
	if (t < h1[i] && t < h2[j]) {
		mayor = (solP > mayor) ? solP : mayor;
		return;
	}

	//Caso recursivo
	//trato de comer de h1
	if (i >= 0 && t >= h1[i]) {
		VA(h1, h2, t - h1[i], i - 1, j, solP + 1, mayor);
	}

	//trato de comer de h2
	if (j >= 0 && t >= h2[j]) {
		VA(h1, h2, t - h2[j], i, j - 1, solP + 1, mayor);
	}
}
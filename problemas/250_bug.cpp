#include <iostream>
using namespace std;

const int MAX = 1000000;

int diaCambioBombin(int v[], int n, int sumDer);

int main() {
	int *v = new int [MAX];
	int n;
	int sum = 0;

	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; ++i) { 
			cin >> v[i]; sum += v[i];
		}
		cout << diaCambioBombin(v, n, sum) << endl;
		cin >> n;
		sum = 0;
	}

	delete[] v;
	return 0;
}

int diaCambioBombin(int v[], int n, int sumDer) {
	int ret = 0;
	int i = 0;
	int sumIzq = 0;
	int minDesgaste = abs(sumDer);
	int minDesgasteAux = abs(sumDer);

	if (sumDer != 0) {
		while (i < n) {
			sumIzq += v[i];
			sumDer -= v[i];
			minDesgasteAux = abs(sumIzq - sumDer);
			if (minDesgasteAux < minDesgaste) {
				minDesgaste = minDesgasteAux;
				ret = i + 1;
			}
			++i;
		}
	}
	
	return ret;
}
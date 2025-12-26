#include <iostream>
using namespace std;

const int MAX = 100;

int mesa(bool v[], int n);

int main() {
	bool v[MAX];
	int n;
	cin >> n;

	while (n) {
		for (int i = 0; i < MAX; ++i) v[i] = false;

		cout << mesa(v, n) << endl;

		cin >> n;
	}

	return 0;
}

int mesa(bool v[], int n) {
	int c = -1, aux = 0, ret = 0;
	for (int i = 0; i < n; ++i) {
		cin >> c;

		--c;

		if (v[c]) {
			--aux;
			v[c] = false;
		}
		else {
			v[c] = true;
			++aux;
		}

		ret = (aux > ret) ? aux : ret;
	}

	return ret;
}

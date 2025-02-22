#include <iostream>

const int MAX = 500000;

int resolver(int v[], int n) {
	int ret = 0;
	int i = n - 2;
	int max = v[n - 1];

	while (i >= 0) {
		if (max > 0) ++ret;
	
		max -= 1;
		max = (max > v[i]) ? max : v[i];
		--i;
	}

	return ret;
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!n) return false;

	int* v = new int[MAX];
	for (int i = 0; i < n; ++i) std::cin >> v[i];

	int sol = resolver(v, n);
	std::cout << sol << '\n';

	delete[] v;
	return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
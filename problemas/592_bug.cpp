#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool esPosible(const std::vector<int>& v, int n, int p, int m) {
	unsigned long long acum = 0;
	for (int i = 0; i < n; i++) {
		acum += (v[i] < m) ? v[i] : m;
		if (acum > p) return false;
	}
	return true;
}

int resolver(const std::vector<int>& v, int n, int p, int vMax) {
	int ini = 1, fin = (p < vMax) ? p: vMax;
	int m = (fin + ini) / 2;

	while (ini < fin) {
		if (esPosible(v, n, p, m)) {
			ini = m;
			if (ini + 1 == fin) return m;
		}
		else fin = m - 1;
		m = (fin + ini) / 2;
	}

	return m;
}

int resuelveCaso() {
	int p;
	std::cin >> p;

	if (!std::cin) return false;

	int n, vMax = 0;
	unsigned long long vAcum = 0;
	std::cin >> n;
	std::vector <int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		vMax = (v[i] > vMax) ? v[i] : vMax;
		vAcum += v[i];
	}

	if (p && n && p > n) {
		if (n == 1) {
			std::cout << std::min(vMax, p) << '\n';
		}
		else if (vAcum <= p) {
			std::cout << vMax << '\n';
		}
		else {
			int sol = resolver(v, n, p, vMax);
			std::cout << sol << '\n';
		}
	}
	else std::cout << "0\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
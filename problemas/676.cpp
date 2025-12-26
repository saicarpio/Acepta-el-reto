#include <iostream>
#include <iomanip>
#include <fstream>

void resuelveCaso() {
	int a, b;
	std::cin >> a >> b;

	int ret1, ret2;
	ret1 = ret2 = 0;

	for (int i = a; i <= b; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			ret2++;
		}
		else { ret1++; }
	}

	std::cout << ret1 << " " << ret2 << "\n";
}

int main() {

	int numC;
	std::cin >> numC;
	for (; numC > 0; numC--) {
		resuelveCaso();
	}

	return 0;
}
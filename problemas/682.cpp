#include <iostream>
#include <iomanip>
#include <fstream>

void resuelveCaso() {
	int n;
	std::cin >> n;

	std::cout << n << " " << 2*n << "\n";
}

int main() {

	int numC;
	std::cin >> numC;
	for (; numC > 0; numC--) {
		resuelveCaso();
	}

	return 0;
}
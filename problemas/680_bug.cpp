#include <iostream>
#include <iomanip>
#include <fstream>

void resuelveCaso() {
	int longitud, avance, retroceso;
	std::cin >> longitud >> avance >> retroceso;

	longitud++;

	if (avance >= longitud) {
		std::cout << "0\n";
		return;
	}

	if (retroceso >= avance) {
		std::cout << "IMPOSIBLE\n";
		return;
	}

	avance -= retroceso;
	int ret = longitud / avance;
	if (longitud % avance == 0) ret--;

	std::cout << ret << "\n";
}

int main() {

	int numC;
	std::cin >> numC;
	for (; numC > 0; numC--) {
		resuelveCaso();
	}

	return 0;
}
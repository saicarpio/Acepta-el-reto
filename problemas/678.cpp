#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

std::string resolver(std::string clave, std::string guess) {
	std::set<char> letras_Clave;
	std::set<char> letras_usadas;
	int fallos = 0;

	for (char c : clave) {
		letras_Clave.insert(c);
	}

	for (char c : guess) {
		if (letras_usadas.find(c) == letras_usadas.end()) {
			if (letras_Clave.find(c) != letras_Clave.end()) {
				letras_Clave.erase(letras_Clave.find(c));
				if (letras_Clave.empty()) return "SALVADO";
			}
			else {
				fallos++;
				if (fallos >= 7) return "AHORCADO";
			}

			letras_usadas.insert(c);
		}
	}

	return "COLGANDO";
}

bool resuelveCaso() {
	std::string clave;
	std::cin >> clave;

	if (clave == ".") return false;

	std::string guess;
	std::cin >> guess;

	std:: string ret = resolver(clave, guess);

	std::cout << ret << "\n";

	return true;
}

int main() {

	while (resuelveCaso());
	return 0;
}
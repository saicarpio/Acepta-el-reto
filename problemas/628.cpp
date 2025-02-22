#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>

using ull = unsigned long long;
using pullull = std::pair<ull, ull>;


pullull resolver(pullull u) {
	pullull bestS = u;
	pullull bestP = u;
	pullull nextU;

	std::cin >> nextU.first >> nextU.second;

	if (!nextU.first) return u; // Si solo hay una uva

	while (nextU.first) {
		// Mejora el sabor o Iguala el sabor pero mejora la piel 
		if (nextU.first > bestS.first || (nextU.first == bestS.first && nextU.second < bestS.second)) {
			bestS = nextU;
		}
		// Mejora la piel o Igual la piel pero mejora el sabor
		if (nextU.second < bestP.second || (nextU.second == bestP.second && nextU.first > bestP.first)) {
			bestP = nextU;
		}

		std::cin >> nextU.first >> nextU.second;
	}

	if (bestS == bestP) return bestS;
	else return { 0, 0 };
}

bool resuelveCaso() {
	pullull uvaIni;
	std::cin >> uvaIni.first;

	if (!std::cin) return false;

	std::cin >> uvaIni.second;

	if (!uvaIni.first) { // Si no hay uvas
		std::cout << "NO HAY MEJOR\n";
	}
	else {
		pullull sol = resolver(uvaIni);
		if (!sol.first) { // Si no hay una uva que sea la mejor
			std::cout << "NO HAY MEJOR\n";
		}
		else { // Si hay una uva que es la mejor
			std::cout << sol.first << ' ' << sol.second << '\n';
		}
	}

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
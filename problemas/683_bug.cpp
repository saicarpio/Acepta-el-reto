#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
	int n;
	std::cin >> n;

	if (!n) return false;

	int x;
	std::cin >> x;

	int min = x, max = x;
	int posMin = 0, posMax = 0;
	int ultMin = 0, ultMax = 0;

	for (int i = 1; i < n; i++) {
		std::cin >> x;

		if (x == min) {
			ultMin = i;

			if (std::abs(posMax - posMin) > std::abs(posMax - i)) {
				posMin = i;
			}
			else if (std::abs(posMax - posMin) > std::abs(i - ultMax)) {
				posMax = ultMax;
				posMin = i;
			}
		}

		if (x == max) {
			ultMax = i;

			if (std::abs(posMax - posMin) > std::abs(i - posMin)) {
				posMax = i;
			}
			else if (std::abs(posMax - posMin) > std::abs(i - ultMin)) {
				posMax = i;
				posMin = ultMin;
			}
		}

		if (x < min) {
			min = x;
			posMin = i;
			ultMin = i;
		}
		
		if (x > max) {
			max = x;
			posMax = i;
			ultMax = i;
		}
	}

	std::cout << min << " " << max << " " << std::abs(posMin - posMax) << "\n";
}

int main() {

	while (resuelveCaso());

	return 0;
}
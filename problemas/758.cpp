#include <iostream>
#include <iomanip>
#include <fstream>

std::pair<int, int> resolver(int n) {
    std::pair<int, int> ret;

    ret.first = n * 2 + (n - 2) * 2 + 4 * ((n / 2) - 1) + 1;
    ret.second = (n * n) - ret.first;

    return ret;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    std::pair<int, int> sol = resolver(n);

    // escribir sol
    std::cout << sol.first << ' ' << sol.second << '\n';

}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
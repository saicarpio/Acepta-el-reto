#include <iostream>
#include <iomanip>
#include <fstream>

void resuelveCaso() {
    int n;
    std::cin >> n;
    std::cout << n * 4 << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
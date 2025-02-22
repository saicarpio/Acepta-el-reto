#include <iostream>
#include <iomanip>
#include <fstream>


void resuelveCaso() {
    int n;
    std::cin >> n;

    if (n > 0) {
        std::cout << n - 1 << std::endl;
    }
    else {
        std::cout << n << std::endl;
    }
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
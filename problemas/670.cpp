#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::vector<long long> tramos;

void resuelveCaso() {
    int numTramos, espacio;
    
    std::cin >> numTramos >> espacio;

    tramos.assign(numTramos, 0);

    int aux;
    for (int i = 0; i < numTramos; i++) {
        std::cin >> aux;
        tramos[i] = aux;
    }

    for (int i = numTramos - 2; i >= 0; i--) {
        if (i + espacio + 1 < numTramos) {
            tramos[i] += tramos[i + espacio + 1];
        }
        tramos[i] = std::max(tramos[i + 1], tramos[i]);
    }

    std::cout << tramos[0] << std::endl;
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>


bool resuelveCaso() {
    int numPuentes;

    std::cin >> numPuentes;

    if (!numPuentes)
        return false;

    int sol = 900;
    int numCarriles;

    for (int i = 0; i < numPuentes; i++) {
        std::cin >> numCarriles;

        int carril, maxCarril = 0;
        for (int j = 0; j < numCarriles; j++) {
            std::cin >> carril;
            maxCarril = std::max(carril, maxCarril);
        }
        sol = std::min(sol, maxCarril);
    }

    std::cout << sol << std::endl;

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
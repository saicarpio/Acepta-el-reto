#include <iostream>
#include <iomanip>
#include <fstream>


int resolver(int a, int b) {
    return 2 * a * b + a + b;
}

void resuelveCaso() {
    int a, b;
    std::cin >> a >> b;

    int sol = resolver(a, b);
    
    std::cout << sol << '\n';

}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
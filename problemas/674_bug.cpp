#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

bool resuelveCaso() {
    long long d, n;
    std::cin >> d >> n;

    if (!d && !n)
        return false;

    long long numCeros;
    numCeros = ((d /25) * 6 ) + ((d % 25) / 5);

    if (numCeros > n) {
        std::cout << "NINGUNO\n";
        return true;
    }

    long long num25 = n / 6;
    long long num5 = n % 6;

    double aprox = (num25 * 25) + (num5 * 5);

    if (aprox < d) {
        std::cout << d << std::endl;
        return true;
    }

    aprox /= (double)d;
    aprox = std::ceil(aprox);
    aprox *= d;

    std::cout << aprox << std::endl;

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
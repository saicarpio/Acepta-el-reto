#include <iostream>
#include <iomanip>
#include <fstream>


unsigned long long resolver(unsigned long long n) {
    unsigned long long ret = 0ULL;
    for (unsigned long long i = 1; i <= n; ++i)
        ret += i*(n-i+1ULL);
    return ret;
}

void resuelveCaso() {
    unsigned long long n;
    std::cin >> n;

    unsigned long long sol = resolver(n);
    
    std::cout << sol << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int resolver(const std::string& bs, const std::string& aux, int ini, int len) {
    //Caso Base
    if (len == 1 || bs.substr(ini, len) == aux.substr(ini, len)) return 1;

    //Caso Recursivo
    int nextL = (len % 2 == 1) ? (len / 2) + 1 : len / 2;

    int left = resolver(bs, aux, ini, nextL);
    int right = resolver(bs, aux, ini + nextL, len / 2);
    return  left + right + 1;
    
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n) return false;

    std::string bit_string;
    std::cin >> bit_string;

    std::string aux;
    aux.assign(n, '0');

    int sol = resolver(bit_string, aux, 0, n);

    std::cout << sol << '\n';

    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int resolver(std::string s) {
    int ret = 0, aux = 0;

    for (char c : s) {
        if (c == 'T') aux++;
        else {
            ret = (aux > ret) ? aux : ret;
            aux = 0;
        }
    }

    ret = (aux > ret) ? aux : ret;

    return ret;
}

void resuelveCaso() {
    std::string s;
    std::cin >> s;

    int sol = resolver(s);
    // escribir sol

    std::cout << sol << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>


int resolver(int n) {
    int ret = 0;
    int top, act;

    // primer elementos
    std::cin >> act;
    if (!act) return 0;
    top = act + n;
    // más elementos
    std::cin >> act;
    while(act) {
        if (act > top) {
            ret++;
            top = act + n;
        }

        std::cin >> act;
    }

    ret++;

    return ret;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (! std::cin)
        return false;

    int sol = resolver(n);

    // escribir sol
    std::cout << sol << '\n';

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
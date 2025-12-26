#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

std::map<std::string, int> mapita;

void leerMapa() {
    int ret = 0;
    int n;
    std::cin >> n;

    std::string s;

    for (int i = 0; i < n; i++) {
        std::cin >> s;
        ret += mapita[s];
        mapita.erase(s);
    }

    std::cout << ret << '\n';
}

void escribirMapa(std::string s) {
    int n;
    std::cin >> n;

    if (mapita.find(s) != mapita.end()) {
        mapita[s] += n;
    }
    else {
        mapita.insert(std::pair<std::string, int>(s, n));
    }
}

void resolver(int n) {
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> s;

        if (s == "?") leerMapa();
        else escribirMapa(s);
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!n)
        return false;

    mapita.clear();
    resolver(n);

    // escribir sol
    std::cout << "---\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

std::map<int, int> m;

int resolver(int n, int d) {
    int ret = 0;
    int g;

    for (int i = 0; i < n; i++) {
        std::cin >> g;
        if (m.find(d-g) != m.end() && m[d-g] > 0) {
            m[d - g]--;
            ret++;
        }
        else if (m.find(g) != m.end()){
            m[g]++;
        }
        else {
            m[g] = 1;
        }
    }

    return ret;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n, d;
    std::cin >> n >> d;

    if (!n || !d)
        return false;

    m.clear();
    int sol = resolver(n, d);

    // escribir sol
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
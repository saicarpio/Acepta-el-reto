#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>

short vLen, k;
std::vector<int> v;
std::set<int> s;

int resolver() {

    s.insert(0);

    for (int i = 1; i < k; i++) {

        std::set<int> aux;

        for (int m : v) {
            for (int n : s) {
                aux.insert(n + m);
            }
        }
        s.swap(aux);
        s.insert(0);
    }

    return s.size() - 1;
}

void resuelveCaso() {
    std::cin >> vLen >> k;

    s.clear();
    v.clear();
    v.resize(vLen);
    for (int i = 0; i < vLen; i++) {
        std::cin >> v[i];
        s.insert(v[i]);
    }

    int sol = resolver();

    std::cout << sol << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
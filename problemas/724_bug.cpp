#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

bool mejorDiff(std::vector<int> const& v, int cutH, int& diff) {
    long long a = 0, b = 0;
    for (int c : v) {
        a += std::max(0, c - cutH);
        b += std::min(cutH, c);
    }

    if (std::abs(a - b) < diff) {
        diff = std::abs(a - b);
        return true;
    }

    return false;
}

//Busqueda binaria en el espacio de soluciones
int resolver(std::vector<int> const& v, int n, int w, int h) {
    int ini = 1, fin = h - 1;
    int m = (fin + ini) / 2;
    if ((fin + ini) % 2 == 1) m++;

    int diff = w;
    int ret = h;

    while (ini <= fin) {
        if (mejorDiff(v, m, diff)) {
            ret = m;
            fin = m-1;
        }
        else {
            ini = m + 1;
        }
        m = (fin + ini) / 2;
        if ((fin + ini) % 2 == 1) m++;
    }

    return ret;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    std::vector<int>v(n);
    long long totalWeight = 0;
    int maxHeigth = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        totalWeight += v[i];
        maxHeigth = (v[i] > maxHeigth) ? v[i] : maxHeigth;
    }

    int sol = resolver(v, n, totalWeight, maxHeigth);

    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}

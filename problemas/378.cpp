#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

int n;
//                    win, spent
std::vector<std::pair<int, int>> mapa;

struct Comparator {                           
    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second > p2.second));
    }
};

bool resolver() {
    std::vector<std::pair<int, int>>::iterator ita, itb;
    ita = itb = mapa.begin();
    ita++;

    for (; ita != mapa.end(); ita++, itb++) {
        if (ita->second < itb->second) return false;
    }

    return true;
}

bool resuelveCaso() {
    std::cin >> n;

    if (!n)
        return false;

    mapa.clear();
    int a, b;
    bool sol;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        mapa.push_back({ b, a });
    }

    std::sort(mapa.begin(), mapa.end(), Comparator());

    sol = resolver();

    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
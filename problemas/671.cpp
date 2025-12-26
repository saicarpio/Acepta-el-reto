#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using ib = std::pair<int, bool>;

int N;
int numComensales, maxTiempo;
int currComemsales, lastEntry;
std::vector<ib> horas;

struct Comparator {                           
    bool operator()(ib const& p1, ib const& p2) {
        return (p1.first < p2.first) || ((p1.first == p2.first) && !p1.second);
    }
};


void resolver() {
    numComensales = currComemsales = 0;
    maxTiempo = lastEntry = 0;

    for (int i = 0; i < horas.size(); ++i) {
        if (horas[i].second) {
            lastEntry = horas[i].first;
            currComemsales++;
            if (numComensales < currComemsales) {
                numComensales = currComemsales;
                maxTiempo = 0;
            }
        }
        else {
            if (numComensales == currComemsales)
                maxTiempo += horas[i].first - lastEntry;
            currComemsales--;
        }
    }
}


bool resuelveCaso() {
    std::cin >> N;
    if (!N)
        return false;

    int ent, sal;
    for (int i = 0; i < N; i++) {
        std::cin >> ent >> sal;
        horas.push_back({ ent, true });
        horas.push_back({ sal, false });
    }

    std::sort(horas.begin(),horas.end(), Comparator());

    resolver();

    std::cout << numComensales << " " << maxTiempo << std::endl;

    horas.clear();

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
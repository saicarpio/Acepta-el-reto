#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int year;
std::vector<int> a, b;

bool resuelveCaso() {
    std::cin >> year;

    if (!year)
        return false;

    a.assign(10, 0);
    b.assign(10, 0);

    for (int i = 0; i < 4; i++) {
        b[year % 10]++;
        year /= 10;
    }

    int aux;
    for (int i = 0; i < 10; i++) {
        std::cin >> aux;
        a[i] = aux;
    }

    int sol = 1000000000;
    for (int i = 0; i < 10; i++) {
        if (b[i]) {
            sol = std::min(sol, a[i] / (b[i] * 3));
        }
    }

    std::cout << sol << std::endl;

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool resolver(const std::vector<int>& v, int a, int b) {
    int p, acum = 0;
    std::string s;
    for (int i = 0; i < b; i++) {
        std::cin >> p;
        if (p > v[i]) {
            std::getline(std::cin, s);
            return false;
        }
        acum += p;
        if (acum > a) {
            std::getline(std::cin, s);
            return false;
        }
    }
    return true;
}

bool resuelveCaso() {
    int a, b;
    std::cin >> a >> b;

    if (!a)
        return false;

    std::vector<int> p(b);
    for (int i = 0; i < b; i++) std::cin >> p[i];

    bool sol = resolver(p, a, b);

    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}
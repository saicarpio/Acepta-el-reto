#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void resuelveConsulta(std::vector<int> const& v) {
    int a, b;
    std::cin >> a >> b;

    if (a - 2 < 0)
        std::cout << v[b - 1] << '\n';
    else
        std::cout << v[b - 1] - v[a - 2] << '\n';
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    std::vector<int> v(n);
    std::cin >> v[0];
    for (int i = 1; i < n; i++) {
        std::cin >> v[i];
        v[i] += v[i - 1];
    }

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveConsulta(v);

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

int n;
std::vector<int> v;

void resolver() {
    int i = n-1;
    while (i > 0 && v[i-1] < v[i]) {
        i--;
    }

    v[i]++;
    for (int j = i+1; j < n; j++) {
        v[j] = v[i];
    }
}

bool resuelveCaso() {
    std::cin >> n;

    if (!n)
        return false;

    v.clear();
    int m;
    for (int i = 0; i < n; i++) {
        std::cin >> m;
        v.push_back(m);
    }

    resolver();

    std::cout << v[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << v[i];
    }
    std::cout << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
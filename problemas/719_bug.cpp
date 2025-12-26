#include <iostream>
#include <iomanip>
#include <fstream>

const int meses[] = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30
};

const int d4y = 1461;

bool resolver(int n) {
    n %= d4y;
    if (n == 0 || (28 <= n && n <= 31) ) return true;
    if (n < 28) return false;

    int a=0, b=1;
    int acum = meses[a];
    while (b < n) {
        if (acum + meses[b] > n) {
            acum -= meses[a];
            a++;
        }
        else {
            acum += meses[b];
            b++;
        }

        if (acum == n) return true;
    }

    return false;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    bool sol = resolver(n);

    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}
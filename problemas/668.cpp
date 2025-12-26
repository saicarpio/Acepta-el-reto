#include <iostream>
#include <iomanip>
#include <fstream>

int a, b, n;

bool resuelveCaso() {
    std::cin >> a >> b >> n;

    if (!a && !b && !n)
        return false;

    n %= 6;

    switch (n) {
    case 0 :
        std::cout << a << std::endl; break;
    case 1:
        std::cout << b << std::endl; break;
    case 2:
        std::cout << b -a << std::endl; break;
    case 3:
        std::cout << -a << std::endl; break;
    case 4:
        std::cout << -b << std::endl; break;
    case 5:
        std::cout << a - b << std::endl; break;
    }

    
    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
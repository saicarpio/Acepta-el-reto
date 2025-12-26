#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
    int a, b;
    std::cin >> a >> b;

    if (!a)
        return false;

    std::cout << "[" << a + (74*b) << " .. " << a + (79 * b) << "]\n";

    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}
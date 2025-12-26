#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

int resolver(int n) {
    return ceil((-1+sqrt(1+8*n))/2);
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!n)
        return false;
    
    int sol = resolver(n);
    
    std::cout << sol << "\n";
    
    return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
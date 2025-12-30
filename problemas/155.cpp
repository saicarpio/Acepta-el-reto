#include <iostream>
#include <iomanip>
#include <fstream>


unsigned long long resolver(int x, int y) {
    return 2ULL* ((unsigned long long)x + y);
}

bool resuelveCaso() {
    int x, y;
    std::cin >> x >> y;
    if (x < 0 || y < 0)
        return false;
    
    unsigned long long sol = resolver(x, y);
    
    std::cout << sol << "\n";
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
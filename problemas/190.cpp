#include <iostream>
#include <iomanip>
#include <fstream>

unsigned long long resolver(int num, int dem) {
    unsigned long long ret = 1;
    for (int i = num; i > dem; --i) {
        ret *= i;
    }
    return ret;
}

bool resuelveCaso() {
    int num, dem;
    std::cin >> num >> dem;
    if (num < dem)
        return false;
    
    unsigned long long sol = resolver(num, dem);
    
    std::cout << sol << "\n";
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
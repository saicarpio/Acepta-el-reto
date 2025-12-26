#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <set>

bool resolver(int n) {
    std::set<int> seen;
    std::cout << n << " ";
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        std::string numStr = std::to_string(n);
        int sum = 0;
        for (char c : numStr) {
            int digit = c - '0';
            sum += digit * digit * digit;
        }
        n = sum;
        std::cout << "- " << n << " ";
    }
    return n == 1;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!n)
        return false;
    
    bool sol = resolver(n);
    
    if (sol) std::cout << "-> cubifinito.\n";
    else std::cout << "-> no cubifinito.\n";

    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

char letra[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void resolver(unsigned long long n, std::vector<std::string>& sol) {
    while (n) {
        std::string s = "";
       
        while (n) {
            n--;
            s.insert(s.begin(), letra[n % 26]);
            n /= 26;
        }

        sol.push_back(s);
        std::cin >> n;
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    unsigned long long n;
    std::cin >> n;

    if (!n)
        return false;

    std::vector<std::string> sol;
    resolver(n, sol);

    // escribir sol
    std::cout << sol[0];
    for (int i = 1; i < sol.size(); i++) {
        std::cout << ' ' << sol[i];
    }
    std::cout << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
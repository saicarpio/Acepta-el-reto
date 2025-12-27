#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <string>

std::map<std::string, int> mapita;

void resolver(int n) {
    for (int i = 0; i < n; ++i) {
        std::string key, value;
        std::getline(std::cin, key);
        std::getline(std::cin, value);
        if (value == "INCORRECTO"){
            if (mapita.find(key) == mapita.end()) {
                mapita[key] = -1;
            }
            else {
                mapita[key]--;
            }
        } else {
            if (mapita.find(key) == mapita.end()) {
                mapita[key] = 1;
            }
            else {
                mapita[key]++;
            }
        }
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    if (!n)
        return false;
    
    mapita.clear();
    resolver(n);
    
    for (auto& pair : mapita) {
        if (pair.second != 0)
            std::cout << pair.first << ", " << pair.second << '\n';
    }
    std::cout << "---\n";
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
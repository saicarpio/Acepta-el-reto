#include <iostream>
#include <iomanip>
#include <fstream>


int resolver() {
    char c;
    int cnt = 0;
    int ignore = 0;
    std::cin.get(c);
    while (c != '\n') {
        if (!ignore){
            if (c == '.'){
                ignore = 2;
                cnt++;
            }
        } else {
            ignore--;
        }
        std::cin.get(c);
    }
    return cnt;
}

void resuelveCaso() {
    int sol = resolver();
    std::cout << sol << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
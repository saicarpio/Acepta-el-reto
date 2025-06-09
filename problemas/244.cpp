#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <algorithm>

std::set<int> row;
std::set<int> column;
std::set<std::pair<int, int>> diagonalR;
std::set<std::pair<int, int>> diagonalL;

bool resolver(int x, int y, int size) {
    int dR_x = x - std::min(x, y);
    int dR_y = y - std::min(x, y);
    int dL_x = x + std::min(size - 1 - x, y);
    int dL_y = y - std::min(size - 1 - x, y);

    if (row.find(x) != row.end() || 
        column.find(y) != column.end() || 
        diagonalR.find({dR_x, dR_y}) != diagonalR.end() || 
        diagonalL.find({dL_x, dL_y}) != diagonalL.end()) {
        return true;
    }

    row.insert(x);
    column.insert(y);
    diagonalR.insert({dR_x, dR_y});
    diagonalL.insert({dL_x, dL_y});
    
    return false;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    
    int size, numReinas;
    std::cin >> size >> numReinas;

    if (!size && !numReinas)
        return false;
    
    row.clear();
    column.clear();
    diagonalR.clear();
    diagonalL.clear();
    int x, y;
    bool sol = false;
    for (int i = 0; i < numReinas; i++) {
        std::cin >> x >> y;
        
        sol = resolver(x - 1, y - 1, size);
        if (sol) {
            break;
        }
    }

    std::string aux;
    std::getline(std::cin, aux); // Leer el resto de la línea para evitar problemas con el siguiente caso
    if (sol) {
        std::cout << "SI\n";
    } else {
        std::cout << "NO\n";
    }
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool resuelveCaso() {
    int rows, cols;
    std::cin >> cols >> rows;
    if (!rows || !cols)
        return false;

    std::cin.ignore(); // consume the newline after reading rows and cols
    rows += 2; // add borders
    cols += 2; // add borders

    // read the page
    std::vector<std::string> page(rows);
    for (int i = 0; i < rows; ++i) {
        std::getline(std::cin, page[i]);
    }

    
    // write page 90 degrees rotated
    std::cout << std::string(rows, '-') << '\n';
    for (int j = cols-2; j > 0; --j) {
        std::cout << "|";
        for (int i = 1; i < rows-1; ++i) {
            std::cout << page[i][j];
        }
        std::cout << "|\n";
    }
    std::cout << std::string(rows, '-') << '\n';

    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
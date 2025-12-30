#include <iostream>
#include <iomanip>
#include <fstream>

int resolver(int N, int x1, int y1, int x2, int y2) {
    if ((x1+y1)%2 != (x2+y2)%2)
        return -1;
    if (x1 == x2 && y1 == y2)
        return 0;
    if (std::abs(x1 - x2) == std::abs(y1 - y2))
        return 1;
    return 2;
}

bool resuelveCaso() {
    int N;
    std::cin >> N;
    if (!N)
        return false;
    
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int sol = resolver(N, x1, y1, x2, y2);
    
    if (sol == -1)
        std::cout << "IMPOSIBLE\n";
    else
        std::cout << sol << "\n";
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
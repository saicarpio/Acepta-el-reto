#include <iostream>
#include <iomanip>
#include <fstream>


bool resolver(int n) {
    char c;
    bool D = false, I = false;
    for (int i = 0; i < n; ++i){
        std::cin >> c;
        if (c == 'D')
            D = true;
        else if (c == 'I')
            I = true;
    }
    return !(I&&D);
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!n)
        return false;
    
    std::cin.ignore(1);

    bool sol = resolver(n);
    
    if (sol)
        std::cout << "TODOS COMEN\n";
    else
        std::cout << "ALGUNO NO COME\n";
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
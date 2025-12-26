#include <iostream>
#include <iomanip>
#include <fstream>

const int MOD = 1000000007;


unsigned long long resolver(int T, int A, int B) {
    int TxT = T * T;
    unsigned long long ret = 0;

    for (int i = A; i <= B; i++) {
        for (int j = 0; j <= i; j++) {
            
        }
    }
    
    return 
}

void resuelveCaso() {
    // leer los datos de la entrada
    int T, A, B;
    std::cin >> T >> A >> B;

    unsigned long long sol = resolver(T, A, B);
    
    // escribir sol
    std::cout << sol << '\n';

}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
#include <iostream>
#include <iomanip>
#include <fstream>


char resolverAux(int r, int& vAux, int & sol) {
    char playerA, playerB;
    
    // Caso Base
    if (r == 1) {
        std::cin >> playerA >> playerB;
        vAux += 2;
    } 
    // Caso Recursivo
    else {
        playerA = resolverAux(r - 1, vAux, sol);
        playerB = resolverAux(r - 1, vAux, sol);
    }


    if (playerA == playerB && playerA == '1') { // Estaban los dos jugadores
        sol++;
        return '1';
    }
    else if (playerA != playerB) { // Solo estaba un jugador
        return '1';
    }
    else { // No hubo jugadores
        return '0';
    }
}


int resolver(int v, int r) {
    int vAux = 0;
    int ret = 0;

    while (v != vAux) {
        resolverAux(r, vAux, ret);
    }
    
    return ret;
}

bool resuelveCaso() {
    int numV, numR;
    std::cin >> numV >> numR;

    if (!numV) return false;

    int sol = resolver(numV, numR);

    std::cout << sol << '\n';

    return true;
}


int main() {

    while (resuelveCaso());

    return 0;
}
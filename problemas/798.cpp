#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <vector>

bool resolver(int n, std::vector<int> const & v) {
    std::stack<int> q;
    int v_idx = 0;

    for (int i = 1; i <= n; ++i) {
        q.push(i);
        while (!q.empty() && q.top() == v[v_idx]) {
            q.pop();
            v_idx++;
        }
    }

    return q.empty();
}


bool resuelveCaso() {
    // leer los datos de la entrada
    int numVag;
    std::cin >> numVag;
    if (!numVag)
        return false;

    std::vector<int> tren(numVag, 0);
    for (int i = 0; i <numVag; i++){
        std::cin >> tren[i];
    }

    bool sol = resolver(numVag, tren);

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";
    
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
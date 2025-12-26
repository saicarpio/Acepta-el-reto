#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


std::vector<int> v;

std::pair<int, int> resolver(int m, int n, const std::vector<int> & v) {
    std::pair<int, int> ret = { 500001, 0}; // {num_vag, prim_vag}
    int i = 0, j = 0;
    int sum = 0;

    while (j < n || sum >= m) {

        if (sum >= m) {
            if (ret.first > (j - i)) {
                ret.first = (j - i);
                ret.second = i + 1;
            }
            sum -= v[i];
            i++;
        }
        else {
            sum += v[j];
            j++;
        }
        
        if (ret.first == 1) break;

    }

    return ret;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int m, n;
    std::cin >> m >> n;

    if (!m && !n)
        return false;

    v.clear();
    int aux;
    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        v.push_back(aux);
    }

    std::pair<int, int> sol = resolver(m, n, v);

    // escribir sol
    if (sol.first == 500001) {
        std::cout << "NO ENTRAN\n";
    }
    else {
        std::cout << sol.first << ' ' << sol.second << '\n';
    }

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
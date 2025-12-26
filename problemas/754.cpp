#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

std::string resolver(std::string s) {
    if (s.length() == 1) return s;

    std::string l = "", c = "", r = "";
    bool yaHayCentro = false;
    int i = 0;

    while (i < s.length()) {
        if (i + 1 < s.length()) {
            if (s[i] == s[i + 1]) {
                l.push_back(s[i]);
                r.insert(r.begin(), s[i + 1]);
                i += 2;
            }
            else {
                if (!yaHayCentro) {
                    yaHayCentro = true;
                    c = s[i];
                    i++;
                }
                else{
                    return "NO HAY";
                }
            }
        }

        else {
            if (!yaHayCentro) {
                yaHayCentro = true;
                c = s[i];
                i++;
            }
            else {
                return "NO HAY";
            }
        }
    }

    return l + c + r;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    std::string s;
    std::cin >> s;

    if (!std::cin)
        return false;

    std::sort(s.begin(), s.end());

    std::string sol = resolver(s);

    // escribir sol
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
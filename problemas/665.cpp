#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

std::string a, b;
std::string delimiter = ".";

size_t pos = 0;
std::string token;


int aM, am, aP;
int bM, bm, bP;

void resuelveCaso() {
    std::cin >> a >> b;

    pos = a.find(delimiter);
    token = a.substr(0, pos);
    aM = std::stoi(token.c_str());
    a.erase(0, pos + delimiter.length());

    pos = a.find(delimiter);
    token = a.substr(0, pos);
    am = std::stoi(token.c_str());
    a.erase(0, pos + delimiter.length());

    aP = std::stoi(a);



    pos = b.find(delimiter);
    token = b.substr(0, pos);
    bM = std::stoi(token.c_str());
    b.erase(0, pos + delimiter.length());

    pos = b.find(delimiter);
    token = b.substr(0, pos);
    bm = std::stoi(token.c_str());
    b.erase(0, pos + delimiter.length());

    bP = std::stoi(b);

    if ((bM == aM + 1 && bm == 0 && bP == 0) ||
        (bM == aM && bm == am + 1 && bP == 0) ||
        (bM == aM && bm == am && bP == aP + 1))
         std::cout << "SI\n";
    else
        std::cout << "NO\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}

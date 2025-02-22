#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>  


bool resolver(int i, int j, int a, int b) {
    if (!(( a <= i && b <= j) || ( a <= j && b <= i))) return false;

    // i = xa + yb
    // j = xb + ya

    // ia = xaa + yab
    // jb = xbb + yab

    long long ia = i * a;
    long long jb = j * b;
    long long aa = a * a;
    long long bb = b * b;

    //ia - jb = xaa - xbb
    //x = (ia-jb)/(aa-bb)
    long long x;
    if (aa - bb == 0) return ia - jb == 0;
    else if ((std::abs(ia - jb) % std::abs(aa - bb)) != 0) return false;
    else x = (ia - jb) / (aa - bb);
    if(x < 0) return false;

    // i = xa + yb
    // y = (i -xa)/b
    long long y;
    if (b == 0) return (i - (x * a)) == 0;
    else if ((std::abs(i - (x * a)) % std::abs(b)) != 0) return false;
    else y = (i - x * a) / b;
    if(y < 0) return false;

    return i == x * a + y * b && j == y * a + x * b;
}

bool resuelveCaso() {
    int i, j, a, b;
    std::cin >> i >> j >> a >> b;
    if (!i)
        return false;

    bool sol = resolver(i, j, a, b);

    if (sol)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}

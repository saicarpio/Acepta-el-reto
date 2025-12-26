#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

std::vector<int> v;

int resolver(){
    int ret = 0;

    for(int i = 0; i < 100; i++){
        if(v[i] >= 6) ret++;
        
        for(int j = i+1; j < 100; j++){
            if(v[i] >= 4){
                if(v[j] >= 4) ret +=2;
                else if(v[j] >= 2) ret++;
            } else if (v[i] >= 2 && v[j] >= 4) ret++;
        }
    }

    return ret;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    v.assign(100, 0);
    int aux;
    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        v[aux - 1]++;
    }

    int sol = resolver();

    std::cout << sol << std::endl;

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
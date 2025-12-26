#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

bool sumaCorrecta(std::string s) {
    int a = 0, b = 0, c = 0;

    int i = 0;

    for(;i < s.length(); i++){
        if (s[i] == ' ') break;
        a = a*10 + (s[i] -'0');
    }

    for(;i < s.length(); i++){
        if (s[i] == ' ') break;
        b = b*10 + (s[i] -'0');
    }

    for(;i < s.length(); i++){
        if (s[i] == ' ') break;
        c = c*10 + (s[i] -'0');
    }

    return a + b == c;

}

std::string BackTracking( 
    //Datos del problema
    std::string s,

    //Sol parcial
    int k,
    int &numSols
) {
    //Busco el '-'
    while(k < s.length() && s[k] != '-') k++;

    //Caso Base
    if(k == s.length()){
        if (sumaCorrecta(s)){
            numSols++;
            if (numSols == 1)
                return s;
            else 
                return "VARIAS";
        } else{
            return "IMPOSIBLE";
        }
    }

    //Caso recursivo
    std::string ret = "IMPOSIBLE", ret_aux;
    for (int i = 0; i < 10; i++) {
        s.replace(k, 1, std::to_string(i));
        ret_aux = BackTracking(s, k+1, numSols);

        if (ret_aux == "VARIAS")
            return ret_aux;
        if (ret_aux != "IMPOSIBLE")
            ret = ret_aux;
    }

    return ret;    
}

std::string resolver(std::string s){
    int foo = 0;
    std::string ret = BackTracking(s, 0, foo);
    return ret;
}

bool resuelveCaso() {
    std::string s;
    std::getline(std::cin, s);

    if (! std::cin)
        return false;

    std::string sol = resolver(s);
    
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
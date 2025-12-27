#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

int resolver(char c) {
    int ret = 0;
    std::stack<char> s;
    while (c != '\n') {
        if (c == 'H' || c == 'h' || c == '@') {
            s.push(c);
        } else if (c == 'M') {
            if (!s.empty() && s.top() == 'H') {
                ret++;
                s.pop();
            } else {
                s.push(c);
            }
        } else if (c == 'm') {
            if (!s.empty() &&s.top() == 'h') {
                ret++;
                s.pop();
            } else {
                s.push(c);
            }
        }
        std::cin.get(c);
    }
    return ret;
}

bool resuelveCaso() {
    char c;
    std::cin.get(c);
    
    if (!std::cin)
        return false;
    
    int sol = resolver(c);
    
    std::cout << sol << '\n';

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
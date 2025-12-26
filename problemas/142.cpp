#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>



int resolver(int n, int m) {
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    while (q.size() > 1) {
        for (int i = 0; i < m; ++i) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
        q.pop(); 
    }
    return (!n)? 0 : q.front();
}

bool resuelveCaso() {
    int n, m;
    std::cin >> n >> m;

    if (n == 0 && m == 0)
        return false;
    
    int sol = resolver(n, m);
    
    std::cout << sol << "\n";
    return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}
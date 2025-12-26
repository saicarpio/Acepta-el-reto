#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <string>

using si = std::set<int>;
using vi = std::vector<int>;
using vsi = std::vector<si>;

const int NOT_VISITED = 0;
const int VISITING = 1;
const int VISITED = 2;

vsi adjList;
vi visited;
int n, c;

bool dfs(int i) {
    visited[i] = VISITING;
    for (int s : adjList[i]) {
        if (visited[s] == VISITING){
            if (adjList[s].find(i) == adjList[s].end()) {
                return true;
            }
        }
        else if (visited[s] == NOT_VISITED)
            if (dfs(s)) return true;
    }
    visited[i] = VISITED;
    return false;
}

bool resolver() {
    for (int i = 0; i < n; i++) {
        if (!adjList[i].empty() && visited[i] == NOT_VISITED) {
            if (dfs(i)) return true;
        }
    }

    return false;
}

bool resuelveCaso() {
    // leer los datos de la entrada

    std::cin >> n >> c;

    if (!std::cin)
        return false;

    adjList.assign(n+1, {});
    visited.assign(n+1, 0);

    int a, b; char comp;
    bool flag = false;
    int i = 0;

    for (; i < c; i++) {
        std::cin >> a >> comp >> b;

        if (comp == '<') {
            if (adjList[a].find(b) == adjList[a].end() && a != b) {
                adjList[b].insert(a);
            }
            else {
                flag = true;
                break;
            }
        }
        else if (comp == '>') {
            if (adjList[b].find(a) == adjList[b].end() && a != b) {
                adjList[a].insert(b);
            }
            else {
                flag = true;
                break;
            }
        }
        else {
            if ((adjList[a].find(b) == adjList[a].end()) && (adjList[b].find(a) == adjList[b].end()) || ((adjList[a].find(b) != adjList[a].end()) && (adjList[b].find(a) != adjList[b].end()))) {
                adjList[a].insert(b);
                adjList[b].insert(a);
            }
            else {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        std::string s;
        while (i < c) {
            getline(std::cin, s);
            i++;
        }
    }

    bool sol = flag? true : resolver();

    // escribir sol
    if (sol) {
        std::cout << "TRAMPAS\n";
    }
    else {
        std::cout << "DESCONFIADO\n";
    }

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
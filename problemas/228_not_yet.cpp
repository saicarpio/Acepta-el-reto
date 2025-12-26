#include <iostream>
#include <iomanip>
#include <fstream>

struct Node {
    char key_value;
    Node* left;
    Node* right;
    Node* parent;
};


TipoSolucion resolver(TipoDatos datos) {


}

bool resuelveCaso() {
    // leer los datos de la entrada
    char c;
    std::cin >> c;

    if (!std::cin)
        return false;

    Node* root = new Node();
    root->key_value = c;
    root->left = nullptr;
    root->right = nullptr;
    root->parent = root;

    Node* it = root;
    Node* it2 = root;

    n->key_value = c;

    while (c != '\n') {}

    TipoSolucion sol = resolver(datos);

    // escribir sol


    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
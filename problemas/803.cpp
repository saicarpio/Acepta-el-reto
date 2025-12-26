#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <vector>
#include <bitset>

// Template class for the Node of a Binary Tree
template <typename T>
class Node {
public:
    // Data held by the node
    T data;  
    // Pointer to the left child
    Node* left;  
    // Pointer to the right child
    Node* right;  

    // Constructor to initialize the node with a value
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Template class for a Binary Tree
template <typename T>
class BinaryTree {
private:
    // Pointer to the root of the tree
    Node<T>* root;  

    // Recursive Function to delete a node from the tree
    Node<T>* deleteRecursive(Node<T>* current, T value) {
        if (current == nullptr) return nullptr;

        if (current->data == value) {
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                return nullptr;
            }
            if (current->left == nullptr) {
                Node<T>* temp = current->right;
                delete current;
                return temp;
            }
            if (current->right == nullptr) {
                Node<T>* temp = current->left;
                delete current;
                return temp;
            }

            Node<T>* successor = findMin(current->right);
            current->data = successor->data;
            current->right = deleteRecursive(current->right, successor->data);
        } else {
            if (value < current->data)
                current->left = deleteRecursive(current->left, value);
            else
                current->right = deleteRecursive(current->right, value);
        }
        return current;
    }

    // Helper Function to find the minimum value node
    Node<T>* findMin(Node<T>* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }

public:
    // Constructor to initialize the tree
    BinaryTree() : root(nullptr) {}

    // Function to insert a node in the binary tree 
    int insertNode(T value) {
        Node<T>* newNode = new Node<T>(value);
        
        if (root == nullptr) {
            root = newNode;
            return 1;
        }
        
        int h = 2;
        std::queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* current = q.front();
            q.pop();

            if (newNode->data < current->data){
                if (current->left == nullptr) {
                    current->left = newNode;
                    return h;
                } else {
                    q.push(current->left);
                    h++;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    return h;
                } else {
                    q.push(current->right);
                    h++;
                }
            }
        }
    }

    // Function to delete a node from the tree
    void deleteNode(T value) {
        root = deleteRecursive(root, value);
    }

};


std::vector<int> resolver(int N, int k) {
    std::vector<int> ret(0);
    BinaryTree<int> tree;
    


    return ret;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int N, k;
    std::cin >> N >> k;
    
    std::vector<int> sol = resolver(N, k);
    
    // escribir sol
    if (sol.empty()){
        std::cout << "IMPOSIBLE\n";
    } else {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); i++){
            std::cout << " " << sol[i];
        }
        std::cout << "\n";
    }
    
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}
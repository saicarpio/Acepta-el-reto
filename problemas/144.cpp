#include <iostream>
#include <iomanip>
#include <fstream>


struct Node {
    char data;
    Node* next;
    
    Node(char val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    Node* current;
public:
    LinkedList() : head(nullptr), tail(nullptr), current(nullptr) {
        head = new Node('\0');
        tail = head;
        current = head;
    }
    
    void insert(char val) {
        Node* newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void supress() {
        if (current->next) {
            Node* toDelete = current->next;
            current->next = toDelete->next;
            if (toDelete == tail) {
                tail = current;
            }
            delete toDelete;
        }
    }

    void gotoBegin() {
        current = head;
    }

    void gotoEnd() {
        current = tail;
    }

    void moveNext() {
        if (current->next) {
            current = current->next;
        }
    }

    void displayAndClear() {
        Node* temp = head->next;
        while (temp) {
            std::cout << temp->data;
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        std::cout << '\n';
        delete head;
        head = tail = current = nullptr;
    }
};


void resolver(char c) {
    LinkedList list;
    while (c != '\n') {
        if (c == '-') {
            list.gotoBegin();
        } else if (c == '+') {
            list.gotoEnd();
        } else if (c == '*') {
            list.moveNext();
        } else if (c == '3') {
            list.supress();
        } else {
            list.insert(c);
        }
        std::cin.get(c);
    }
    list.displayAndClear();
}

bool resuelveCaso() {
    char c;
    std::cin.get(c);
    
    if (!std::cin)
        return false;
    
    resolver(c);
    
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
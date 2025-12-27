#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

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


void resolver(std::string line) {
    LinkedList list;
    for (char ch : line) {
        if (ch == '-') {
            list.gotoBegin();
        } else if (ch == '+') {
            list.gotoEnd();
        } else if (ch == '*') {
            list.moveNext();
        } else if (ch == '3') {
            list.supress();
        } else {
            list.insert(ch);
        }
    }
    list.displayAndClear();
}

bool resuelveCaso() {
    std::string line;
    std::getline(std::cin, line);
    
    if (!std::cin)
        return false;
    
    resolver(line);
    
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}
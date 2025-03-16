
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int key;
    node *prev;
    node *next;
};

void rPrint(node *n, stringstream &buf) {
    buf << n->key;
    if (n->next!= nullptr) {
        buf << " ";
        rPrint(n->next, buf);
    }
}

void deleteNode(node *n, node *&first, node *&last) {
    if (n->prev!= nullptr && n->next!= nullptr) {
        //swap
        n->prev->next = n->next;
        n->next->prev = n->prev;
    } else if (n->next == nullptr && n->prev == nullptr) {
        first = nullptr;
        last = nullptr;
    } else if (n->prev == nullptr) {
        first = n->next;
        n->next->prev = nullptr;
    } else if (n->next == nullptr) {
        last = n->prev;
        n->prev->next = nullptr;
    }
}

node *initNode(int key) {
    node *n = new node();
    n->key = key;
    return n;
}

int main() {
    string line;
    getline(cin, line);

    node *first = nullptr;
    node *last = nullptr;

    while (getline(cin, line)) {
        if (line == "deleteFirst") {
            deleteNode(first, first, last);
        } else if (line == "deleteLast") {
            deleteNode(last, first, last);
        } else {
            stringstream ss(line);
            string cmd;
            ss >> cmd;
            if (cmd == "delete") {
                int k;
                ss >> k;
                for (node *a = first; a!= nullptr; a = a->next) {
                    if (a->key == k) {
                        deleteNode(a, first, last);
                        break;
                    }
                }
            } else if (cmd == "insert") {
                int k;
                ss >> k;
                node *n = initNode(k);
                n->next = first;
                if (first!= nullptr) {
                    first->prev = n;
                }
                first = n;
                if (last == nullptr) {
                    last = n;
                }
            }
        }
    }

    stringstream buf;
    rPrint(first, buf);
    cout << buf.str() << endl;

    return 0;
}

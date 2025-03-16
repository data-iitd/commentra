#include <iostream>
#include <string>

struct Node {
    unsigned int key;
    Node* next;
    Node* prev;
};

typedef Node* NodePointer;

NodePointer nil; // A dummy node used for easier list manipulation

// Searches for a node with the specified key in the list
NodePointer listSearch(int key);

// Initializes the list by creating a dummy node and setting its next and prev pointers
void init(void);

// Prints the entire list from the first node to the last node
void printList(void);

// Deletes the specified node from the list
void deleteNode(NodePointer t);

// Deletes the first node in the list
void deleteFirst(void);

// Deletes the last node in the list
void deleteLast(void);

// Deletes the node with the specified key from the list
void deleteNodeByKey(int key);

// Inserts a new node with the given key at the beginning of the list
void insert(int key);

int main() {
    int key, n;
    std::string command;
    int size = 0; // Keeps track of the number of elements in the list
    int np = 0, nd = 0; // Counters for insertions and deletions

    std::cin >> n;

    init(); // Initialize the list

    for (int i = 0; i < n; i++) {
        std::cin >> command >> key;

        if (command[0] == 'i') { // Insert a new node with the specified key
            insert(key);
            np++;
            size++;
        } else if (command[0] == 'd') { // Delete a node with the specified key or the first/last node
            if (command.length() > 6) {
                if (command[6] == 'F') // Delete the first node
                    deleteFirst();
                else if (command[6] == 'L') // Delete the last node
                    deleteLast();
            } else {
                deleteNodeByKey(key);
                nd++;
            }
            size--;
        }
    }

    printList(); // Print the final list

    return 0;
}

// Searches for a node with the specified key in the list
NodePointer listSearch(int key) {
    NodePointer cur = nil->next;

    while (cur != nil && cur->key != key)
        cur = cur->next;

    return cur;
}

// Initializes the list by creating a dummy node and setting its next and prev pointers to point to itself
void init(void) {
    nil = new Node;
    nil->next = nil;
    nil->prev = nil;
}

// Prints the entire list from the first node to the last node
void printList(void) {
    NodePointer cur = nil->next;
    bool isFirst = true;
    while (true) {
        if (cur == nil) break;
        if (!isFirst) std::cout << " ";
        std::cout << cur->key;
        cur = cur->next;
        isFirst = false;
    }
    std::cout << std::endl;
}

// Deletes the specified node from the list
void deleteNode(NodePointer t) {
    t->prev->next = t->next;
    t->next->prev = t->prev;
    delete t;
}

// Deletes the first node in the list
void deleteFirst(void) {
    NodePointer t = nil->next;
    if (t == nil)
        return;

    deleteNode(t);
}

// Deletes the last node in the list
void deleteLast(void) {
    NodePointer t = nil->prev;
    if (t == nil)
        return;

    deleteNode(t);
}

// Deletes the node with the specified key from the list
void deleteNodeByKey(int key) {
    NodePointer t = listSearch(key);

    if (t == nil)
        return;

    deleteNode(t);
}

// Inserts a new node with the given key at the beginning of the list
void insert(int key) {
    NodePointer x = new Node;
    x->key = key;

    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define U1 unsigned char
#define S1 char
#define S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH (10) /* Command length */

class ST_NODE {
public:
    ST_NODE* st_parent;
    ST_NODE* st_left;
    ST_NODE* st_right;
    S4 s4_key;

    ST_NODE(S4 key) : st_parent(nullptr), st_left(nullptr), st_right(nullptr), s4_key(key) {}
};

void vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key);
void vd_d_print(ST_NODE* st_ap_root);
static void vd_s_printPreOrder(ST_NODE* st_ap_node);
static void vd_s_printInOrder(ST_NODE* st_ap_node);

int main() {
    ST_NODE* st_tp_root = nullptr; // Initialize the root of the tree to nullptr
    S4 s4_t_numCommand;
    S4 s4_t_iCommand;
    S1 s1_tp_command[COMMAND_LENGTH];
    S4 s4_t_insertKey;

    // Read the number of commands
    std::cin >> s4_t_numCommand;

    // Execute commands
    for (s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++) {
        // Read the command
        std::cin >> s1_tp_command;

        // Execute the command based on its type
        if (strcmp(s1_tp_command, "insert") == 0) {
            // If the command is "insert", read the key value and insert it into the tree
            std::cin >> s4_t_insertKey;
            vd_d_insert(&st_tp_root, s4_t_insertKey);
        } else {
            // If the command is "print", print the tree
            vd_d_print(st_tp_root);
        }
    }

    return 0;
}

// Insert a new node into the binary search tree
void vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key) {
    ST_NODE* st_tp_parentNode = nullptr;
    ST_NODE* st_tp_indexNode = *st_ap2_root;
    ST_NODE* st_tp_insertNode = new ST_NODE(s4_a_key); // Create a new node with the given key

    while (st_tp_indexNode != nullptr) {
        st_tp_parentNode = st_tp_indexNode;
        if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key) {
            st_tp_indexNode = st_tp_indexNode->st_left;
        } else {
            st_tp_indexNode = st_tp_indexNode->st_right;
        }
    }
    st_tp_insertNode->st_parent = st_tp_parentNode; // Set the parent of the new node

    if (st_tp_parentNode == nullptr) {
        *st_ap2_root = st_tp_insertNode; // If the tree was empty, set the root to the new node
    } else if (s4_a_key < st_tp_parentNode->s4_key) {
        st_tp_parentNode->st_left = st_tp_insertNode; // Insert the new node as the left child
    } else {
        st_tp_parentNode->st_right = st_tp_insertNode; // Insert the new node as the right child
    }
}

// Print the tree in both pre-order and in-order traversal
void vd_d_print(ST_NODE* st_ap_root) {
    vd_s_printInOrder(st_ap_root); // Print the tree in in-order traversal
    std::cout << std::endl;
    vd_s_printPreOrder(st_ap_root); // Print the tree in pre-order traversal
    std::cout << std::endl;
}

// Pre-order traversal of the tree
static void vd_s_printPreOrder(ST_NODE* st_ap_node) {
    if (st_ap_node == nullptr) {
        return;
    }

    std::cout << " " << st_ap_node->s4_key; // Print the current node's key
    vd_s_printPreOrder(st_ap_node->st_left); // Recursively print the left subtree
    vd_s_printPreOrder(st_ap_node->st_right); // Recursively print the right subtree
}

// In-order traversal of the tree
static void vd_s_printInOrder(ST_NODE* st_ap_node) {
    if (st_ap_node == nullptr) {
        return;
    }

    vd_s_printInOrder(st_ap_node->st_left); // Recursively print the left subtree
    std::cout << " " << st_ap_node->s4_key; // Print the current node's key
    vd_s_printInOrder(st_ap_node->st_right); // Recursively print the right subtree
}

// Constructor-like function to create a new ST_NODE
ST_NODE* st_dp_newST_NODE(S4 s4_a_key) {
    return new ST_NODE(s4_a_key); // Allocate memory for the new node
}


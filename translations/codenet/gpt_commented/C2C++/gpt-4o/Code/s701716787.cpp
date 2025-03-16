#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define U1 unsigned char
#define S1 char
#define S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH (10)   // Length of command input

class ST_NODE {
public:
    ST_NODE* st_parent;  // Pointer to the parent node
    ST_NODE* st_left;    // Pointer to the left child node
    ST_NODE* st_right;   // Pointer to the right child node
    S4 s4_key;          // Key value of the node

    ST_NODE(S4 key) : st_parent(nullptr), st_left(nullptr), st_right(nullptr), s4_key(key) {}
};

// Function prototypes
VD vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key); // Function to insert a key into the binary search tree
VD vd_d_print(ST_NODE*);        // Function to print the binary search tree
static VD vd_s_printPreOrder(ST_NODE*); // Function to print the tree in pre-order
static VD vd_s_printInOrder(ST_NODE*);  // Function to print the tree in in-order
ST_NODE* st_dp_newST_NODE(S4); // Function to create a new node

int main() {
    ST_NODE* st_tp_root = nullptr; // Root of the binary search tree
    S4 s4_t_numCommand; // Number of commands to process
    S4 s4_t_insertKey;  // Key to be inserted
    std::string command; // Command input buffer

    // Read the number of commands from user input
    std::cin >> s4_t_numCommand;

    // Execute commands based on user input
    for (S4 s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++) {
        // Read the command (insert or print)
        std::cin >> command;

        // Execute the command based on its type
        if (command == "insert") {
            // If the command is "insert", read the key value to insert
            std::cin >> s4_t_insertKey;
            vd_d_insert(&st_tp_root, s4_t_insertKey); // Insert the key into the tree
        } else {
            vd_d_print(st_tp_root); // Print the current state of the tree
        }
    }

    return 0; // Return success
}

// Function to insert a key into the binary search tree
VD vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key) {
    ST_NODE* st_tp_parentNode = nullptr; // Pointer to track the parent node
    ST_NODE* st_tp_indexNode = *st_ap2_root; // Start from the root
    ST_NODE* st_tp_insertNode = st_dp_newST_NODE(s4_a_key); // Create a new node with the given key

    // Traverse the tree to find the correct insertion point
    while (st_tp_indexNode != nullptr) {
        st_tp_parentNode = st_tp_indexNode; // Update parent node
        if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key) {
            st_tp_indexNode = st_tp_indexNode->st_left; // Go left
        } else {
            st_tp_indexNode = st_tp_indexNode->st_right; // Go right
        }
    }
    st_tp_insertNode->st_parent = st_tp_parentNode; // Set parent for the new node

    // Insert the new node in the tree
    if (st_tp_parentNode == nullptr) {
        *st_ap2_root = st_tp_insertNode; // Tree was empty, new node becomes root
    } else if (s4_a_key < st_tp_parentNode->s4_key) {
        st_tp_parentNode->st_left = st_tp_insertNode; // Insert as left child
    } else {
        st_tp_parentNode->st_right = st_tp_insertNode; // Insert as right child
    }
}

// Function to print the binary search tree
VD vd_d_print(ST_NODE* st_ap_root) {
    vd_s_printInOrder(st_ap_root); // Print in-order
    std::cout << std::endl;
    vd_s_printPreOrder(st_ap_root); // Print pre-order
    std::cout << std::endl;
}

// Function to print the tree in pre-order
static VD vd_s_printPreOrder(ST_NODE* st_ap_node) {
    if (st_ap_node == nullptr) {
        return; // Base case: if the node is NULL, return
    }

    std::cout << " " << st_ap_node->s4_key; // Print the key of the current node
    vd_s_printPreOrder(st_ap_node->st_left); // Recursively print left subtree
    vd_s_printPreOrder(st_ap_node->st_right); // Recursively print right subtree
}

// Function to print the tree in in-order
static VD vd_s_printInOrder(ST_NODE* st_ap_node) {
    if (st_ap_node == nullptr) {
        return; // Base case: if the node is NULL, return
    }

    vd_s_printInOrder(st_ap_node->st_left); // Recursively print left subtree
    std::cout << " " << st_ap_node->s4_key; // Print the key of the current node
    vd_s_printInOrder(st_ap_node->st_right); // Recursively print right subtree
}

// Function to create a new node
ST_NODE* st_dp_newST_NODE(S4 s4_a_key) {
    return new ST_NODE(s4_a_key); // Create and return a new node
}


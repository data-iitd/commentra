#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define COMMAND_LENGTH (10) // Command length

typedef int S4; // Assuming S4 is an integer type
typedef void VD; // Assuming VD is a void type
typedef char S1[COMMAND_LENGTH]; // Command string type

struct ST_NODE {
    ST_NODE* st_parent;
    ST_NODE* st_left;
    ST_NODE* st_right;
    S4 s4_key;
};

VD vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key); // Function prototype for inserting a new node
VD vd_d_print(ST_NODE*); // Function prototype for printing the tree
static VD vd_s_printPreOrder(ST_NODE*); // Function prototype for pre-order traversal
static VD vd_s_printInOrder(ST_NODE*); // Function prototype for in-order traversal
ST_NODE* st_dp_newST_NODE(S4); // Function prototype for creating a new node

int main() // Main function
{
    ST_NODE* st_tp_root = nullptr; // Pointer to the root node of the AVL tree
    S4 s4_t_numCommand; // Number of commands to be executed
    S4 s4_t_insertKey; // Key to be inserted
    S1 s1_tp_command; // Command string

    // Read the number of commands from the standard input
    std::cout << "Enter the number of commands: ";
    std::cin >> s4_t_numCommand;

    // Process each command
    for (S4 s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
    {
        // Read the command string
        std::cout << "Enter the command (insert or print): ";
        std::cin >> s1_tp_command;

        // Determine the type of command based on the command string
        if (strcmp(s1_tp_command, "insert") == 0) // If the command is "insert"
        {
            // Read the key to be inserted
            std::cout << "Enter the key to be inserted: ";
            std::cin >> s4_t_insertKey;

            // Call the insert function to insert the new node
            vd_d_insert(&st_tp_root, s4_t_insertKey);
        }
        else // If the command is "print"
        {
            // Call the print function to print the tree
            vd_d_print(st_tp_root);
        }
    }

    return 0; // Return success
}

VD vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key) // Function for inserting a new node into the AVL tree
{
    ST_NODE* st_tp_parentNode = nullptr; // Pointer to the parent node of the new node
    ST_NODE* st_tp_indexNode = *st_ap2_root; // Pointer to the node where the new node should be inserted
    ST_NODE* st_tp_insertNode = st_dp_newST_NODE(s4_a_key); // Create a new node with the given key

    // Search for the position to insert the new node
    while (st_tp_indexNode != nullptr)
    {
        st_tp_parentNode = st_tp_indexNode; // Move the parent node pointer one step back

        if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key) // If the new node's key is smaller than the current node's key
        {
            st_tp_indexNode = st_tp_indexNode->st_left; // Move to the left subtree
        }
        else // If the new node's key is larger than or equal to the current node's key
        {
            st_tp_indexNode = st_tp_indexNode->st_right; // Move to the right subtree
        }
    }

    // Insert the new node at the appropriate position
    st_tp_insertNode->st_parent = st_tp_parentNode;

    if (st_tp_parentNode == nullptr) // If the new node is the root node
    {
        *st_ap2_root = st_tp_insertNode; // Set the root node to the new node
    }
    else if (s4_a_key < st_tp_parentNode->s4_key) // If the new node's key is smaller than the parent node's key
    {
        st_tp_parentNode->st_left = st_tp_insertNode; // Set the left child of the parent node to the new node
    }
    else // If the new node's key is larger than or equal to the parent node's key
    {
        st_tp_parentNode->st_right = st_tp_insertNode; // Set the right child of the parent node to the new node
    }
}

VD vd_d_print(ST_NODE* st_ap_root) // Function for printing the AVL tree
{
    vd_s_printInOrder(st_ap_root); // Call the in-order traversal function to print the tree in sorted order
    std::cout << std::endl;
    vd_s_printPreOrder(st_ap_root); // Call the pre-order traversal function to print the tree in the recursive order
    std::cout << std::endl;
}

// st_ap_node…exploration start node
static VD vd_s_printPreOrder(ST_NODE* st_ap_node) // Function for pre-order traversal of the AVL tree
{
    if (st_ap_node == nullptr) // If the node is NULL, return
    {
        return;
    }

    std::cout << " " << st_ap_node->s4_key; // Print the key of the current node
    vd_s_printPreOrder(st_ap_node->st_left); // Recursively print the left subtree
    vd_s_printPreOrder(st_ap_node->st_right); // Recursively print the right subtree
}

// st_ap_node…exploration start node
static VD vd_s_printInOrder(ST_NODE* st_ap_node) // Function for in-order traversal of the AVL tree
{
    if (st_ap_node == nullptr) // If the node is NULL, return
    {
        return;
    }

    vd_s_printInOrder(st_ap_node->st_left); // Recursively print the left subtree
    std::cout << " " << st_ap_node->s4_key; // Print the key of the current node
    vd_s_printInOrder(st_ap_node->st_right); // Recursively print the right subtree
}

// ST_NODE constructor
ST_NODE* st_dp_newST_NODE(S4 s4_a_key) // Function for creating a new node
{
    ST_NODE* st_tp_node = new ST_NODE; // Allocate memory for the new node
    st_tp_node->st_parent = nullptr; // Initialize the parent pointer to NULL
    st_tp_node->st_left = nullptr; // Initialize the left child pointer to NULL
    st_tp_node->st_right = nullptr; // Initialize the right child pointer to NULL
    st_tp_node->s4_key = s4_a_key; // Set the key of the new node

    return st_tp_node; // Return the new node
}

// <END-OF-CODE>

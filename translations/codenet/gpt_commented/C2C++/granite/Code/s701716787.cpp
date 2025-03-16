
#include <iostream>
#include <string.h>

#define COMMAND_LENGTH (10)   /* Length of command input */

struct ST_NODE
{
    ST_NODE* st_parent;  // Pointer to the parent node
    ST_NODE* st_left;    // Pointer to the left child node
    ST_NODE* st_right;   // Pointer to the right child node
    int s4_key;          // Key value of the node
};

void d_d_insert(ST_NODE**, int); // Function to insert a key into the binary search tree
void d_d_print(ST_NODE*);        // Function to print the binary search tree
static void s_printPreOrder(ST_NODE*); // Function to print the tree in pre-order
static void s_printInOrder(ST_NODE*);  // Function to print the tree in in-order
ST_NODE* dp_newST_NODE(int); // Function to create a new node

int main()
{
    ST_NODE* tp_root; // Root of the binary search tree
    int t_numCommand; // Number of commands to process
    int t_iCommand;   // Command index
    char t_command[COMMAND_LENGTH]; // Command input buffer
    int t_insertKey;  // Key to be inserted
    int t_RtnStrcmp;  // Result of string comparison for command

    tp_root = (ST_NODE*)NULL; // Initialize the root to NULL

    // Read the number of commands from user input
    std::cin >> t_numCommand;

    // Execute commands based on user input
    for (t_iCommand = 0; t_iCommand < t_numCommand; t_iCommand++)
    {
        // Read the command (insert or print)
        std::cin >> t_command;

        // Execute the command based on its type
        // Assumes only "insert" and "print" commands are valid
        t_RtnStrcmp = strcmp(t_command, "insert");
        if (t_RtnStrcmp == 0)
        {
            // If the command is "insert", read the key value to insert
            std::cin >> t_insertKey;
            d_d_insert(&tp_root, t_insertKey); // Insert the key into the tree
        }
        else
        {
            d_d_print(tp_root); // Print the current state of the tree
        }
    }

    return 0; // Return success
}

// Function to insert a key into the binary search tree
void d_d_insert(ST_NODE** ap2_root, int a_key)
{
    ST_NODE* tp_parentNode; // Pointer to track the parent node
    ST_NODE* tp_indexNode;  // Pointer for traversal
    ST_NODE* tp_insertNode;  // New node to be inserted

    // Create a new node with the given key
    tp_insertNode = dp_newST_NODE(a_key);

    tp_parentNode = (ST_NODE*)NULL; // Initialize parent node to NULL
    tp_indexNode = *ap2_root;    // Start from the root

    // Traverse the tree to find the correct insertion point
    while (tp_indexNode!= (ST_NODE*)NULL)
    {
        tp_parentNode = tp_indexNode; // Update parent node
        if (tp_insertNode->s4_key < tp_indexNode->s4_key)
        {
            tp_indexNode = tp_indexNode->st_left; // Go left
        }
        else
        {
            tp_indexNode = tp_indexNode->st_right; // Go right
        }
    }
    tp_insertNode->st_parent = tp_parentNode; // Set parent for the new node

    // Insert the new node in the tree
    if (tp_parentNode == (ST_NODE*)NULL)
    {
        *ap2_root = tp_insertNode; // Tree was empty, new node becomes root
    }
    else if (a_key < tp_parentNode->s4_key)
    {
        tp_parentNode->st_left = tp_insertNode; // Insert as left child
    }
    else
    {
        tp_parentNode->st_right = tp_insertNode; // Insert as right child
    }
}

// Function to print the binary search tree
void d_d_print(ST_NODE* ap_root)
{
    s_printInOrder(ap_root); // Print in-order
    std::cout << "\n";
    s_printPreOrder(ap_root); // Print pre-order
    std::cout << "\n";
}

// Function to print the tree in pre-order
static void s_printPreOrder(ST_NODE* ap_node)
{
    if (ap_node == (ST_NODE*)NULL)
    {
        return; // Base case: if the node is NULL, return
    }

    std::cout << " " << ap_node->s4_key; // Print the key of the current node
    s_printPreOrder(ap_node->st_left); // Recursively print left subtree
    s_printPreOrder(ap_node->st_right); // Recursively print right subtree
}

// Function to print the tree in in-order
static void s_printInOrder(ST_NODE* ap_node)
{
    static int s_printedNumNode = 0; // Static variable to count printed nodes

    if (ap_node == (ST_NODE*)NULL)
    {
        return; // Base case: if the node is NULL, return
    }

    s_printInOrder(ap_node->st_left); // Recursively print left subtree
    std::cout << " " << ap_node->s4_key; // Print the key of the current node
    s_printInOrder(ap_node->st_right); // Recursively print right subtree
}

// Function to create a new node
ST_NODE* dp_newST_NODE(int a_key)
{
    ST_NODE* tp_node; // Pointer to the new node
    tp_node = (ST_NODE*)malloc(sizeof(ST_NODE)); // Allocate memory for the new node
    tp_node->st_parent = (ST_NODE*)NULL; // Initialize parent to NULL
    tp_node->st_left = (ST_NODE*)NULL;   // Initialize left child to NULL
    tp_node->st_right = (ST_NODE*)NULL;  // Initialize right child to NULL
    tp_node->s4_key = a_key; // Set the key value

    return(tp_node); // Return the new node
}


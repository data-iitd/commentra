#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define U1 unsigned char
#define S1 char
#define S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH (10)   /* Length of command input */

using namespace std;

typedef struct st_node ST_NODE;
typedef struct st_node
{
    ST_NODE* st_parent;  // Pointer to the parent node
    ST_NODE* st_left;    // Pointer to the left child node
    ST_NODE* st_right;   // Pointer to the right child node
    S4 s4_key;          // Key value of the node
};

// Function prototypes
VD vd_d_insert(ST_NODE**, S4); // Function to insert a key into the binary search tree
VD vd_d_print(ST_NODE*);        // Function to print the binary search tree
static VD vd_s_printPreOrder(ST_NODE*); // Function to print the tree in pre-order
static VD vd_s_printInOrder(ST_NODE*);  // Function to print the tree in in-order
ST_NODE* st_dp_newST_NODE(S4); // Function to create a new node

S4 main()
{
    ST_NODE* st_tp_root; // Root of the binary search tree
    S4 s4_t_numCommand; // Number of commands to process
    S4 s4_t_iCommand;   // Command index
    S1 s1_tp_command[COMMAND_LENGTH]; // Command input buffer
    S4 s4_t_insertKey;  // Key to be inserted
    S4 s4_t_RtnStrcmp;  // Result of string comparison for command

    st_tp_root = (ST_NODE*)NULL; // Initialize the root to NULL

    // Read the number of commands from user input
    (VD)cin >> s4_t_numCommand;

    // Execute commands based on user input
    for (s4_t_iCommand = (S4)0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
    {
        // Read the command (insert or print)
        (VD)cin >> s1_tp_command;

        // Execute the command based on its type
        // Assumes only "insert" and "print" commands are valid
        s4_t_RtnStrcmp = (S4)strcmp(s1_tp_command, "insert");
        if (s4_t_RtnStrcmp == (S4)0)
        {
            // If the command is "insert", read the key value to insert
            (VD)cin >> s4_t_insertKey;
            vd_d_insert(&st_tp_root, s4_t_insertKey); // Insert the key into the tree
        }
        else
        {
            vd_d_print(st_tp_root); // Print the current state of the tree
        }
    }

    return((S4)0); // Return success
}

// Function to insert a key into the binary search tree
VD vd_d_insert(ST_NODE** st_ap2_root, S4 s4_a_key)
{
    ST_NODE* st_tp_parentNode; // Pointer to track the parent node
    ST_NODE* st_tp_indexNode;  // Pointer for traversal
    ST_NODE* st_tp_insertNode;  // New node to be inserted

    // Create a new node with the given key
    st_tp_insertNode = st_dp_newST_NODE(s4_a_key);

    st_tp_parentNode = (ST_NODE*)NULL; // Initialize parent node to NULL
    st_tp_indexNode = *st_ap2_root;    // Start from the root

    // Traverse the tree to find the correct insertion point
    while (st_tp_indexNode != (ST_NODE*)NULL)
    {
        st_tp_parentNode = st_tp_indexNode; // Update parent node
        if (st_tp_insertNode->s4_key < st_tp_indexNode->s4_key)
        {
            st_tp_indexNode = st_tp_indexNode->st_left; // Go left
        }
        else
        {
            st_tp_indexNode = st_tp_indexNode->st_right; // Go right
        }
    }
    st_tp_insertNode->st_parent = st_tp_parentNode; // Set parent for the new node

    // Insert the new node in the tree
    if (st_tp_parentNode == (ST_NODE*)NULL)
    {
        *st_ap2_root = st_tp_insertNode; // Tree was empty, new node becomes root
    }
    else if (s4_a_key < st_tp_parentNode->s4_key)
    {
        st_tp_parentNode->st_left = st_tp_insertNode; // Insert as left child
    }
    else
    {
        st_tp_parentNode->st_right = st_tp_insertNode; // Insert as right child
    }
}

// Function to print the binary search tree
VD vd_d_print(ST_NODE* st_ap_root)
{
    vd_s_printInOrder(st_ap_root); // Print in-order
    cout << endl;
    vd_s_printPreOrder(st_ap_root); // Print pre-order
    cout << endl;
}

// Function to print the tree in pre-order
static VD vd_s_printPreOrder(ST_NODE* st_ap_node)
{
    if (st_ap_node == (ST_NODE*)NULL)
    {
        return; // Base case: if the node is NULL, return
    }

    cout << " " << st_ap_node->s4_key; // Print the key of the current node
    vd_s_printPreOrder(st_ap_node->st_left); // Recursively print left subtree
    vd_s_printPreOrder(st_ap_node->st_right); // Recursively print right subtree
}

// Function to print the tree in in-order
static VD vd_s_printInOrder(ST_NODE* st_ap_node)
{
    static S4 s4_s_printedNumNode = (S4)0; // Static variable to count printed nodes

    if (st_ap_node == (ST_NODE*)NULL)
    {
        return; // Base case: if the node is NULL, return
    }

    vd_s_printInOrder(st_ap_node->st_left); // Recursively print left subtree
    cout << " " << st_ap_node->s4_key; // Print the key of the current node
    vd_s_printInOrder(st_ap_node->st_right); // Recursively print right subtree
}

// Function to create a new node
ST_NODE* st_dp_newST_NODE(S4 s4_a_key)
{
    ST_NODE* st_tp_node; // Pointer to the new node
    st_tp_node = (ST_NODE*)malloc(sizeof(ST_NODE)); // Allocate memory for the new node
    st_tp_node->st_parent = (ST_NODE*)NULL; // Initialize parent to NULL
    st_tp_node->st_left = (ST_NODE*)NULL;   // Initialize left child to NULL
    st_tp_node->st_right = (ST_NODE*)NULL;  // Initialize right child to NULL
    st_tp_node->s4_key = s4_a_key; // Set the key value

    return(st_tp_node); // Return the new node
}


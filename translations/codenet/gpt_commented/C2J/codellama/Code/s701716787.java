
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define U1 unsigned char
#define S1 char
#define S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH (10)   /* Length of command input */

class Node {
    Node st_parent;  // Pointer to the parent node
    Node st_left;    // Pointer to the left child node
    Node st_right;   // Pointer to the right child node
    S4 s4_key;          // Key value of the node

    public Node(S4 s4_a_key) {
        st_parent = null; // Initialize parent to NULL
        st_left = null;   // Initialize left child to NULL
        st_right = null;  // Initialize right child to NULL
        s4_key = s4_a_key; // Set the key value
    }

    public void setParent(Node st_ap_parent) {
        st_parent = st_ap_parent;
    }

    public void setLeft(Node st_ap_left) {
        st_left = st_ap_left;
    }

    public void setRight(Node st_ap_right) {
        st_right = st_ap_right;
    }

    public Node getParent() {
        return st_parent;
    }

    public Node getLeft() {
        return st_left;
    }

    public Node getRight() {
        return st_right;
    }

    public S4 getKey() {
        return s4_key;
    }
}

// Function prototypes
VD vd_d_insert(Node** st_ap2_root, S4 s4_a_key); // Function to insert a key into the binary search tree
VD vd_d_print(Node* st_ap_root);        // Function to print the binary search tree
static VD vd_s_printPreOrder(Node* st_ap_node); // Function to print the tree in pre-order
static VD vd_s_printInOrder(Node* st_ap_node);  // Function to print the tree in in-order
Node* st_dp_newST_NODE(S4 s4_a_key); // Function to create a new node

S4 main()
{
    Node* st_tp_root; // Root of the binary search tree
    S4 s4_t_numCommand; // Number of commands to process
    S4 s4_t_iCommand;   // Command index
    S1 s1_tp_command[COMMAND_LENGTH]; // Command input buffer
    S4 s4_t_insertKey;  // Key to be inserted
    S4 s4_t_RtnStrcmp;  // Result of string comparison for command

    st_tp_root = null; // Initialize the root to NULL

    // Read the number of commands from user input
    (VD)scanf("%d", &s4_t_numCommand);

    // Execute commands based on user input
    for (s4_t_iCommand = (S4)0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++)
    {
        // Read the command (insert or print)
        (VD)scanf("%s", s1_tp_command);

        // Execute the command based on its type
        // Assumes only "insert" and "print" commands are valid
        s4_t_RtnStrcmp = (S4)strcmp(s1_tp_command, "insert");
        if (s4_t_RtnStrcmp == (S4)0)
        {
            // If the command is "insert", read the key value to insert
            (VD)scanf("%d", &s4_t_insertKey);
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
VD vd_d_insert(Node** st_ap2_root, S4 s4_a_key)
{
    Node st_tp_parentNode; // Pointer to track the parent node
    Node st_tp_indexNode;  // Pointer for traversal
    Node st_tp_insertNode;  // New node to be inserted

    // Create a new node with the given key
    st_tp_insertNode = new Node(s4_a_key);

    st_tp_parentNode = null; // Initialize parent node to NULL
    st_tp_indexNode = *st_ap2_root;    // Start from the root

    // Traverse the tree to find the correct insertion point
    while (st_tp_indexNode != null)
    {
        st_tp_parentNode = st_tp_indexNode; // Update parent node
        if (st_tp_insertNode.getKey() < st_tp_indexNode.getKey())
        {
            st_tp_indexNode = st_tp_indexNode.getLeft(); // Go left
        }
        else
        {
            st_tp_indexNode = st_tp_indexNode.getRight(); // Go right
        }
    }
    st_tp_insertNode.setParent(st_tp_parentNode); // Set parent for the new node

    // Insert the new node in the tree
    if (st_tp_parentNode == null)
    {
        *st_ap2_root = st_tp_insertNode; // Tree was empty, new node becomes root
    }
    else if (s4_a_key < st_tp_parentNode.getKey())
    {
        st_tp_parentNode.setLeft(st_tp_insertNode); // Insert as left child
    }
    else
    {
        st_tp_parentNode.setRight(st_tp_insertNode); // Insert as right child
    }
}

// Function to print the binary search tree
VD vd_d_print(Node st_ap_root)
{
    vd_s_printInOrder(st_ap_root); // Print in-order
    System.out.println();
    vd_s_printPreOrder(st_ap_root); // Print pre-order
    System.out.println();
}

// Function to print the tree in pre-order
static VD vd_s_printPreOrder(Node st_ap_node)
{
    if (st_ap_node == null)
    {
        return; // Base case: if the node is NULL, return
    }

    System.out.print(" " + st_ap_node.getKey()); // Print the key of the current node
    vd_s_printPreOrder(st_ap_node.getLeft()); // Recursively print left subtree
    vd_s_printPreOrder(st_ap_node.getRight()); // Recursively print right subtree
}

// Function to print the tree in in-order
static VD vd_s_printInOrder(Node st_ap_node)
{
    static S4 s4_s_printedNumNode = (S4)0; // Static variable to count printed nodes

    if (st_ap_node == null)
    {
        return; // Base case: if the node is NULL, return
    }

    vd_s_printInOrder(st_ap_node.getLeft()); // Recursively print left subtree
    System.out.print(" " + st_ap_node.getKey()); // Print the key of the current node
    vd_s_printInOrder(st_ap_node.getRight()); // Recursively print right subtree
}

// Function to create a new node
Node st_dp_newST_NODE(S4 s4_a_key)
{
    Node st_tp_node; // Pointer to the new node
    st_tp_node = new Node(s4_a_key); // Allocate memory for the new node
    st_tp_node.setParent(null); // Initialize parent to NULL
    st_tp_node.setLeft(null);   // Initialize left child to NULL
    st_tp_node.setRight(null);  // Initialize right child to NULL
    st_tp_node.setKey(s4_a_key); // Set the key value

    return(st_tp_node); // Return the new node
}


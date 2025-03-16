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

class st_node:
    def __init__(self, s4_key):
        self.st_parent = None  # Pointer to the parent node
        self.st_left = None    # Pointer to the left child node
        self.st_right = None   # Pointer to the right child node
        self.s4_key = s4_key    # Key value of the node

# Function prototypes
def vd_d_insert(st_ap2_root, s4_a_key): # Function to insert a key into the binary search tree
    st_tp_parentNode = None # Pointer to track the parent node
    st_tp_indexNode = st_ap2_root # Start from the root

    # Traverse the tree to find the correct insertion point
    while st_tp_indexNode != None:
        st_tp_parentNode = st_tp_indexNode # Update parent node
        if s4_a_key < st_tp_indexNode.s4_key:
            st_tp_indexNode = st_tp_indexNode.st_left # Go left
        else:
            st_tp_indexNode = st_tp_indexNode.st_right # Go right

    st_tp_insertNode = st_node(s4_a_key) # Create a new node with the given key
    st_tp_insertNode.st_parent = st_tp_parentNode # Set parent for the new node

    # Insert the new node in the tree
    if st_tp_parentNode == None:
        st_ap2_root = st_tp_insertNode # Tree was empty, new node becomes root
    elif s4_a_key < st_tp_parentNode.s4_key:
        st_tp_parentNode.st_left = st_tp_insertNode # Insert as left child
    else:
        st_tp_parentNode.st_right = st_tp_insertNode # Insert as right child

def vd_d_print(st_ap_root): # Function to print the binary search tree
    vd_s_printInOrder(st_ap_root) # Print in-order
    print()
    vd_s_printPreOrder(st_ap_root) # Print pre-order
    print()

def vd_s_printPreOrder(st_ap_node): # Function to print the tree in pre-order
    if st_ap_node == None:
        return # Base case: if the node is NULL, return

    print(" %d" % st_ap_node.s4_key) # Print the key of the current node
    vd_s_printPreOrder(st_ap_node.st_left) # Recursively print left subtree
    vd_s_printPreOrder(st_ap_node.st_right) # Recursively print right subtree

def vd_s_printInOrder(st_ap_node): # Function to print the tree in in-order
    s4_s_printedNumNode = 0 # Static variable to count printed nodes

    if st_ap_node == None:
        return # Base case: if the node is NULL, return

    vd_s_printInOrder(st_ap_node.st_left) # Recursively print left subtree
    print(" %d" % st_ap_node.s4_key) # Print the key of the current node
    vd_s_printInOrder(st_ap_node.st_right) # Recursively print right subtree

def st_dp_newST_NODE(s4_a_key): # Function to create a new node
    st_tp_node = st_node(s4_a_key) # Pointer to the new node
    st_tp_node.st_parent = None # Initialize parent to NULL
    st_tp_node.st_left = None # Initialize left child to NULL
    st_tp_node.st_right = None # Initialize right child to NULL

    return st_tp_node # Return the new node

s4_t_numCommand = 0 # Number of commands to process
s4_t_iCommand = 0   # Command index
s1_tp_command = "" # Command input buffer
s4_t_insertKey = 0  # Key to be inserted
s4_t_RtnStrcmp = 0  # Result of string comparison for command

st_tp_root = None # Root of the binary search tree

# Read the number of commands from user input
s4_t_numCommand = int(input())

# Execute commands based on user input
for s4_t_iCommand in range(s4_t_numCommand):
    # Read the command (insert or print)
    s1_tp_command = input()

    # Execute the command based on its type
    # Assumes only "insert" and "print" commands are valid
    s4_t_RtnStrcmp = strcmp(s1_tp_command, "insert")
    if s4_t_RtnStrcmp == 0:
        # If the command is "insert", read the key value to insert
        s4_t_insertKey = int(input())
        vd_d_insert(st_tp_root, s4_t_insertKey) # Insert the key into the tree
    else:
        vd_d_print(st_tp_root) # Print the current state of the tree

# 
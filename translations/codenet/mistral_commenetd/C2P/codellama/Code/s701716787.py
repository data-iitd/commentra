#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

class ST_NODE:
    def __init__(self, s4_key):
        self.st_parent = None
        self.st_left = None
        self.st_right = None
        self.s4_key = s4_key

def vd_d_insert(st_ap2_root, s4_a_key): # Function for inserting a new node into the AVL tree
    st_tp_parentNode = None # Pointer to the parent node of the new node
    st_tp_indexNode = st_ap2_root # Pointer to the node where the new node should be inserted
    st_tp_insertNode = ST_NODE(s4_a_key) # Pointer to the new node

    # Search for the position to insert the new node
    while st_tp_indexNode != None:
        st_tp_parentNode = st_tp_indexNode # Move the parent node pointer one step back

        if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key: # If the new node's key is smaller than the current node's key
            st_tp_indexNode = st_tp_indexNode.st_left # Move to the left subtree
        else: # If the new node's key is larger than or equal to the current node's key
            st_tp_indexNode = st_tp_indexNode.st_right # Move to the right subtree

    # Insert the new node at the appropriate position
    st_tp_insertNode.st_parent = st_tp_parentNode

    if st_tp_parentNode == None: # If the new node is the root node
        st_ap2_root = st_tp_insertNode # Set the root node to the new node
    elif st_tp_insertNode.s4_key < st_tp_parentNode.s4_key: # If the new node's key is smaller than the parent node's key
        st_tp_parentNode.st_left = st_tp_insertNode # Set the left child of the parent node to the new node
    else: # If the new node's key is larger than or equal to the parent node's key
        st_tp_parentNode.st_right = st_tp_insertNode # Set the right child of the parent node to the new node

def vd_d_print(st_ap_root): # Function for printing the AVL tree
    vd_s_printInOrder(st_ap_root) # Call the in-order traversal function to print the tree in sorted order
    print()
    vd_s_printPreOrder(st_ap_root) # Call the pre-order traversal function to print the tree in the recursive order
    print()

# st_ap_node…exploration start node
def vd_s_printPreOrder(st_ap_node): # Function for pre-order traversal of the AVL tree
    if st_ap_node == None: # If the node is NULL, return
        return

    print(" %d" % st_ap_node.s4_key) # Print the key of the current node
    vd_s_printPreOrder(st_ap_node.st_left) # Recursively print the left subtree
    vd_s_printPreOrder(st_ap_node.st_right) # Recursively print the right subtree

# st_ap_node…exploration start node
def vd_s_printInOrder(st_ap_node): # Function for in-order traversal of the AVL tree
    s4_s_printedNumNode = 0 # A static variable to keep track of the number of nodes printed

    if st_ap_node == None: # If the node is NULL, return
        return

    vd_s_printInOrder(st_ap_node.st_left) # Recursively print the left subtree
    print(" %d" % st_ap_node.s4_key) # Print the key of the current node
    vd_s_printInOrder(st_ap_node.st_right) # Recursively print the right subtree

# ST_NODE constructor
def st_dp_newST_NODE(s4_a_key): # Function for creating a new node
    st_tp_node = ST_NODE(s4_a_key) # Pointer to the new node
    st_tp_node.st_parent = None # Initialize the parent pointer to NULL
    st_tp_node.st_left = None # Initialize the left child pointer to NULL
    st_tp_node.st_right = None # Initialize the right child pointer to NULL
    st_tp_node.s4_key = s4_a_key # Set the key of the new node

    return st_tp_node # Return the new node

# Main function
def main():
    st_tp_root = None # Pointer to the root node of the AVL tree
    s4_t_numCommand = 0 # Number of commands to be executed
    s4_t_iCommand = 0 # Index of the current command
    s1_tp_command = [0] * COMMAND_LENGTH # Command string
    s4_t_insertKey = 0 # Key to be inserted
    s4_t_RtnStrcmp = 0 # Return value of strcmp() function

    st_tp_root = None # Initialize the root node to NULL

    # Read the number of commands from the standard input
    print("Enter the number of commands: ", end="")
    s4_t_numCommand = int(input())

    # Process each command
    for s4_t_iCommand in range(s4_t_numCommand):
        # Read the command string
        print("Enter the command (insert or print): ", end="")
        s1_tp_command = input()

        # Determine the type of command based on the command string
        s4_t_RtnStrcmp = strcmp(s1_tp_command, "insert")
        if s4_t_RtnStrcmp == 0: # If the command is "insert"
            # Read the key to be inserted
            print("Enter the key to be inserted: ", end="")
            s4_t_insertKey = int(input())

            # Call the insert function to insert the new node
            vd_d_insert(st_tp_root, s4_t_insertKey)
        else: # If the command is "print"
            # Call the print function to print the tree
            vd_d_print(st_tp_root)

    return 0 # Return success

# strcmp() function
def strcmp(s1_a_str1, s1_a_str2):
    return s1_a_str1 == s1_a_str2

if __name__ == "__main__":
    main()


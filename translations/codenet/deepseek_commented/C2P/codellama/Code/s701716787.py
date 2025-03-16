#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define U1 unsigned char
#define S1 char
#define	S4 int
#define DU double
#define VD void

#define COMMAND_LENGTH     (10)   /* 命令の文字数 */

class ST_NODE:
    def __init__(self, s4_a_key):
        self.st_parent = None
        self.st_left = None
        self.st_right = None
        self.s4_key = s4_a_key

def vd_d_insert(st_ap2_root, s4_a_key):
    st_tp_parentNode = None
    st_tp_indexNode = st_ap2_root
    st_tp_insertNode = ST_NODE(s4_a_key)

    while st_tp_indexNode != None:
        st_tp_parentNode = st_tp_indexNode
        if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key:
            st_tp_indexNode = st_tp_indexNode.st_left
        else:
            st_tp_indexNode = st_tp_indexNode.st_right

    st_tp_insertNode.st_parent = st_tp_parentNode

    if st_tp_parentNode == None:
        st_ap2_root = st_tp_insertNode
    elif st_tp_insertNode.s4_key < st_tp_parentNode.s4_key:
        st_tp_parentNode.st_left = st_tp_insertNode
    else:
        st_tp_parentNode.st_right = st_tp_insertNode

def vd_d_print(st_ap_root):
    vd_s_printInOrder(st_ap_root)
    print()
    vd_s_printPreOrder(st_ap_root)
    print()

def vd_s_printPreOrder(st_ap_node):
    if st_ap_node == None:
        return

    print(" %d" % st_ap_node.s4_key, end="")
    vd_s_printPreOrder(st_ap_node.st_left)
    vd_s_printPreOrder(st_ap_node.st_right)

def vd_s_printInOrder(st_ap_node):
    if st_ap_node == None:
        return

    vd_s_printInOrder(st_ap_node.st_left)
    print(" %d" % st_ap_node.s4_key, end="")
    vd_s_printInOrder(st_ap_node.st_right)

def st_dp_newST_NODE(s4_a_key):
    st_tp_node = ST_NODE(s4_a_key)
    return st_tp_node

def main():
    st_tp_root = None
    s4_t_numCommand = 0
    s4_t_iCommand = 0
    s1_tp_command = [0] * COMMAND_LENGTH
    s4_t_insertKey = 0
    s4_t_RtnStrcmp = 0

    st_tp_root = None # Initialize the root of the tree to NULL

    # Read the number of commands
    s4_t_numCommand = int(input())

    # Execute commands
    for s4_t_iCommand in range(s4_t_numCommand):
        # Read the command
        s1_tp_command = input()

        # Execute the command based on its type
        s4_t_RtnStrcmp = strcmp(s1_tp_command, "insert")
        if s4_t_RtnStrcmp == 0:
            # If the command is "insert", read the key value and insert it into the tree
            s4_t_insertKey = int(input())
            vd_d_insert(st_tp_root, s4_t_insertKey)
        else:
            # If the command is "print", print the tree
            vd_d_print(st_tp_root)

if __name__ == "__main__":
    main()


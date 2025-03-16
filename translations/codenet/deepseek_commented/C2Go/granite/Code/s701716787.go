
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type ST_NODE struct {
	st_parent *ST_NODE
	st_left   *ST_NODE
	st_right  *ST_NODE
	s4_key    int
}

func main() {
	var st_tp_root *ST_NODE
	var s4_t_numCommand int
	var s4_t_iCommand int
	var s1_tp_command string
	var s4_t_insertKey int
	var s4_t_RtnStrcmp int

	st_tp_root = nil // Initialize the root of the tree to nil

	// Read the number of commands
	fmt.Scan(&s4_t_numCommand)

	// Execute commands
	for s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++ {
		// Read the command
		fmt.Scan(&s1_tp_command)

		// Execute the command based on its type
		s4_t_RtnStrcmp = strings.Compare(s1_tp_command, "insert")
		if s4_t_RtnStrcmp == 0 {
			// If the command is "insert", read the key value and insert it into the tree
			fmt.Scan(&s4_t_insertKey)
			vd_d_insert(&st_tp_root, s4_t_insertKey)
		} else {
			// If the command is "print", print the tree
			vd_d_print(st_tp_root)
		}
	}
}

// Insert a new node into the binary search tree
func vd_d_insert(st_ap2_root **ST_NODE, s4_a_key int) {
	var st_tp_parentNode *ST_NODE
	var st_tp_indexNode *ST_NODE
	var st_tp_insertNode *ST_NODE

	st_tp_insertNode = st_dp_newST_NODE(s4_a_key) // Create a new node with the given key

	st_tp_parentNode = nil
	st_tp_indexNode = *st_ap2_root

	for st_tp_indexNode!= nil {
		st_tp_parentNode = st_tp_indexNode
		if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key {
			st_tp_indexNode = st_tp_indexNode.st_left
		} else {
			st_tp_indexNode = st_tp_indexNode.st_right
		}
	}
	st_tp_insertNode.st_parent = st_tp_parentNode // Set the parent of the new node

	if st_tp_parentNode == nil {
		*st_ap2_root = st_tp_insertNode // If the tree was empty, set the root to the new node
	} else if s4_a_key < st_tp_parentNode.s4_key {
		st_tp_parentNode.st_left = st_tp_insertNode // Insert the new node as the left child if the key is less than the parent's key
	} else {
		st_tp_parentNode.st_right = st_tp_insertNode // Insert the new node as the right child if the key is greater than or equal to the parent's key
	}
}

// Print the tree in both pre-order and in-order traversal
func vd_d_print(st_ap_root *ST_NODE) {
	vd_s_printInOrder(st_ap_root) // Print the tree in in-order traversal
	fmt.Println()
	vd_s_printPreOrder(st_ap_root) // Print the tree in pre-order traversal
	fmt.Println()
}

// Pre-order traversal of the tree
func vd_s_printPreOrder(st_ap_node *ST_NODE) {
	if st_ap_node == nil {
		return
	}

	fmt.Printf(" %d", st_ap_node.s4_key) // Print the current node's key
	vd_s_printPreOrder(st_ap_node.st_left) // Recursively print the left subtree
	vd_s_printPreOrder(st_ap_node.st_right) // Recursively print the right subtree
}

// In-order traversal of the tree
func vd_s_printInOrder(st_ap_node *ST_NODE) {
	static s4_s_printedNumNode int = 0 // Static variable to keep track of the number of nodes printed

	if st_ap_node == nil {
		return
	}

	vd_s_printInOrder(st_ap_node.st_left) // Recursively print the left subtree
	fmt.Printf(" %d", st_ap_node.s4_key) // Print the current node's key
	vd_s_printInOrder(st_ap_node.st_right) // Recursively print the right subtree
}

// Constructor-like function to create a new ST_NODE
func st_dp_newST_NODE(s4_a_key int) *ST_NODE {
	var st_tp_node *ST_NODE
	st_tp_node = new(ST_NODE) // Allocate memory for the new node
	st_tp_node.st_parent = nil // Initialize the parent pointer to nil
	st_tp_node.st_left = nil // Initialize the left child pointer to nil
	st_tp_node.st_right = nil // Initialize the right child pointer to nil
	st_tp_node.s4_key = s4_a_key // Set the key of the new node

	return st_tp_node
}


<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Constants
const (
	COMMAND_LENGTH = 10
)

// Structures
type st_node struct {
	st_parent *st_node
	st_left   *st_node
	st_right  *st_node
	s4_key    int
}

// Function prototypes
func vd_d_insert(st_ap2_root *st_node, s4_a_key int)
func vd_d_print(st_ap_root *st_node)
func vd_s_printPreOrder(st_ap_node *st_node)
func vd_s_printInOrder(st_ap_node *st_node)
func st_dp_newST_NODE(s4_a_key int) *st_node

func main() {
	var st_tp_root *st_node
	var s4_t_numCommand int
	var s4_t_iCommand int
	var s1_tp_command [COMMAND_LENGTH]byte
	var s4_t_insertKey int
	var s4_t_RtnStrcmp int

	st_tp_root = nil

	// Read the number of commands from the standard input
	fmt.Print("Enter the number of commands: ")
	fmt.Scanf("%d", &s4_t_numCommand)

	// Process each command
	for s4_t_iCommand = 0; s4_t_iCommand < s4_t_numCommand; s4_t_iCommand++ {
		// Read the command string
		fmt.Print("Enter the command (insert or print): ")
		fmt.Scanf("%s", &s1_tp_command)

		// Determine the type of command based on the command string
		s4_t_RtnStrcmp = strings.Compare(string(s1_tp_command), "insert")
		if s4_t_RtnStrcmp == 0 { // If the command is "insert"
			// Read the key to be inserted
			fmt.Print("Enter the key to be inserted: ")
			fmt.Scanf("%d", &s4_t_insertKey)

			// Call the insert function to insert the new node
			vd_d_insert(&st_tp_root, s4_t_insertKey)
		} else { // If the command is "print"
			// Call the print function to print the tree
			vd_d_print(st_tp_root)
		}
	}
}

func vd_d_insert(st_ap2_root *st_node, s4_a_key int) {
	var st_tp_parentNode *st_node
	var st_tp_indexNode *st_node
	var st_tp_insertNode *st_node

	st_tp_insertNode = st_dp_newST_NODE(s4_a_key)

	st_tp_parentNode = nil
	st_tp_indexNode = st_ap2_root

	// Search for the position to insert the new node
	for st_tp_indexNode!= nil {
		st_tp_parentNode = st_tp_indexNode

		if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key { // If the new node's key is smaller than the current node's key
			st_tp_indexNode = st_tp_indexNode.st_left // Move to the left subtree
		} else { // If the new node's key is larger than or equal to the current node's key
			st_tp_indexNode = st_tp_indexNode.st_right // Move to the right subtree
		}
	}

	// Insert the new node at the appropriate position
	st_tp_insertNode.st_parent = st_tp_parentNode

	if st_tp_parentNode == nil { // If the new node is the root node
		*st_ap2_root = st_tp_insertNode // Set the root node to the new node
	} else if s4_a_key < st_tp_parentNode.s4_key { // If the new node's key is smaller than the parent node's key
		st_tp_parentNode.st_left = st_tp_insertNode // Set the left child of the parent node to the new node
	} else { // If the new node's key is larger than or equal to the parent node's key
		st_tp_parentNode.st_right = st_tp_insertNode // Set the right child of the parent node to the new node
	}
}

func vd_d_print(st_ap_root *st_node) {
<<<<<<< HEAD
	vd_s_printInOrder(st_ap_root)
	fmt.Println()
	vd_s_printPreOrder(st_ap_root)
=======
	vd_s_printInOrder(st_ap_root) // Call the in-order traversal function to print the tree in sorted order
	fmt.Println()
	vd_s_printPreOrder(st_ap_root) // Call the pre-order traversal function to print the tree in the recursive order
>>>>>>> 98c87cb78a (data updated)
	fmt.Println()
}

// st_ap_node…exploration start node
func vd_s_printPreOrder(st_ap_node *st_node) {
	if st_ap_node == nil { // If the node is NULL, return
		return
	}

	fmt.Printf(" %d", st_ap_node.s4_key) // Print the key of the current node
	vd_s_printPreOrder(st_ap_node.st_left) // Recursively print the left subtree
	vd_s_printPreOrder(st_ap_node.st_right) // Recursively print the right subtree
}

// st_ap_node…exploration start node
func vd_s_printInOrder(st_ap_node *st_node) {
	var s4_s_printedNumNode int

	s4_s_printedNumNode = 0

	if st_ap_node == nil { // If the node is NULL, return
		return
	}

	vd_s_printInOrder(st_ap_node.st_left) // Recursively print the left subtree
	fmt.Printf(" %d", st_ap_node.s4_key) // Print the key of the current node
	vd_s_printInOrder(st_ap_node.st_right) // Recursively print the right subtree
}

// ST_NODE constructor
func st_dp_newST_NODE(s4_a_key int) *st_node {
	var st_tp_node *st_node
	st_tp_node = new(st_node)
	st_tp_node.st_parent = nil
	st_tp_node.st_left = nil
	st_tp_node.st_right = nil
	st_tp_node.s4_key = s4_a_key

	return st_tp_node
}


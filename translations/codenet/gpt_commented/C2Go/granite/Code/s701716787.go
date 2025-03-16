
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
	st_tp_root := new(ST_NODE) // Root of the binary search tree
	s4_t_numCommand, _ := strconv.Atoi(readInput()) // Number of commands to process
	s4_t_iCommand := 0 // Command index
	s1_tp_command := make([]string, COMMAND_LENGTH) // Command input buffer
	s4_t_insertKey := 0 // Key to be inserted
	s4_t_RtnStrcmp := 0 // Result of string comparison for command

	for s4_t_iCommand < s4_t_numCommand {
		s1_tp_command = strings.Split(readInput(), " ") // Read the command (insert or print)
		s4_t_RtnStrcmp = strings.Compare(s1_tp_command[0], "insert")
		if s4_t_RtnStrcmp == 0 {
			s4_t_insertKey, _ = strconv.Atoi(s1_tp_command[1]) // If the command is "insert", read the key value to insert
			vd_d_insert(&st_tp_root, s4_t_insertKey) // Insert the key into the tree
		} else {
			vd_d_print(st_tp_root) // Print the current state of the tree
		}
		s4_t_iCommand++ // Increment the command index
	}
}

// Function to insert a key into the binary search tree
func vd_d_insert(st_ap2_root **ST_NODE, s4_a_key int) {
	st_tp_parentNode := new(ST_NODE) // Pointer to track the parent node
	st_tp_indexNode := *st_ap2_root   // Start from the root
	st_tp_insertNode := new(ST_NODE) // New node to be inserted

	st_tp_insertNode.s4_key = s4_a_key // Set the key value for the new node

	st_tp_parentNode = nil // Initialize parent node to NULL
	st_tp_indexNode = *st_ap2_root // Start from the root

	// Traverse the tree to find the correct insertion point
	for st_tp_indexNode!= nil {
		st_tp_parentNode = st_tp_indexNode // Update parent node
		if st_tp_insertNode.s4_key < st_tp_indexNode.s4_key {
			st_tp_indexNode = st_tp_indexNode.st_left // Go left
		} else {
			st_tp_indexNode = st_tp_indexNode.st_right // Go right
		}
	}
	st_tp_insertNode.st_parent = st_tp_parentNode // Set parent for the new node

	// Insert the new node in the tree
	if st_tp_parentNode == nil {
		*st_ap2_root = st_tp_insertNode // Tree was empty, new node becomes root
	} else if st_tp_insertNode.s4_key < st_tp_parentNode.s4_key {
		st_tp_parentNode.st_left = st_tp_insertNode // Insert as left child
	} else {
		st_tp_parentNode.st_right = st_tp_insertNode // Insert as right child
	}
}

// Function to print the binary search tree
func vd_d_print(st_ap_root *ST_NODE) {
	vd_s_printInOrder(st_ap_root) // Print in-order
	fmt.Println()
	vd_s_printPreOrder(st_ap_root) // Print pre-order
	fmt.Println()
}

// Function to print the tree in pre-order
func vd_s_printPreOrder(st_ap_node *ST_NODE) {
	if st_ap_node == nil {
		return // Base case: if the node is NULL, return
	}

	fmt.Printf(" %d", st_ap_node.s4_key) // Print the key of the current node
	vd_s_printPreOrder(st_ap_node.st_left) // Recursively print left subtree
	vd_s_printPreOrder(st_ap_node.st_right) // Recursively print right subtree
}

// Function to print the tree in in-order
func vd_s_printInOrder(st_ap_node *ST_NODE) {
	static s4_s_printedNumNode int = 0 // Static variable to count printed nodes

	if st_ap_node == nil {
		return // Base case: if the node is NULL, return
	}

	vd_s_printInOrder(st_ap_node.st_left) // Recursively print left subtree
	fmt.Printf(" %d", st_ap_node.s4_key) // Print the key of the current node
	vd_s_printInOrder(st_ap_node.st_right) // Recursively print right subtree
}

// Function to read input from the user
func readInput() string {
	reader := bufio.NewReader(os.Stdin)
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}


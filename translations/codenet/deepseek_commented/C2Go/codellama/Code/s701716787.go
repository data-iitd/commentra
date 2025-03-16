
package main

import (
	"fmt"
)

type stNode struct {
	stParent *stNode
	stLeft   *stNode
	stRight  *stNode
	s4Key    int
}

func vdDInsert(stpRoot **stNode, s4aKey int) {
	stpInsertNode := stDpNewSTNode(s4aKey)

	stpParentNode := (*stNode)(nil)
	stpIndexNode := *stpRoot

	for stpIndexNode != nil {
		stpParentNode = stpIndexNode
		if stpInsertNode.s4Key < stpIndexNode.s4Key {
			stpIndexNode = stpIndexNode.stLeft
		} else {
			stpIndexNode = stpIndexNode.stRight
		}
	}
	stpInsertNode.stParent = stpParentNode // Set the parent of the new node

	if stpParentNode == nil {
		*stpRoot = stpInsertNode // If the tree was empty, set the root to the new node
	} else if stpInsertNode.s4Key < stpParentNode.s4Key {
		stpParentNode.stLeft = stpInsertNode // Insert the new node as the left child if the key is less than the parent's key
	} else {
		stpParentNode.stRight = stpInsertNode // Insert the new node as the right child if the key is greater than or equal to the parent's key
	}
}

func vdDPrint(stpRoot *stNode) {
	vdSPrintInOrder(stpRoot) // Print the tree in in-order traversal
	fmt.Println()
	vdSPrintPreOrder(stpRoot) // Print the tree in pre-order traversal
	fmt.Println()
}

func vdSPrintPreOrder(stpNode *stNode) {
	if stpNode == nil {
		return
	}

	fmt.Printf(" %d", stpNode.s4Key) // Print the current node's key
	vdSPrintPreOrder(stpNode.stLeft)  // Recursively print the left subtree
	vdSPrintPreOrder(stpNode.stRight) // Recursively print the right subtree
}

func vdSPrintInOrder(stpNode *stNode) {
	s4sPrintedNumNode := 0 // Static variable to keep track of the number of nodes printed

	if stpNode == nil {
		return
	}

	vdSPrintInOrder(stpNode.stLeft) // Recursively print the left subtree
	fmt.Printf(" %d", stpNode.s4Key) // Print the current node's key
	vdSPrintInOrder(stpNode.stRight) // Recursively print the right subtree
}

func stDPNewSTNode(s4aKey int) *stNode {
	stpNode := &stNode{}
	stpNode.stParent = nil // Initialize the parent pointer to NULL
	stpNode.stLeft = nil // Initialize the left child pointer to NULL
	stpNode.stRight = nil // Initialize the right child pointer to NULL
	stpNode.s4Key = s4aKey // Set the key of the new node

	return stpNode
}

func main() {
	stpRoot := (*stNode)(nil) // Initialize the root of the tree to NULL

	// Read the number of commands
	var s4tNumCommand int
	fmt.Scanf("%d", &s4tNumCommand)

	// Execute commands
	for s4tICommand := 0; s4tICommand < s4tNumCommand; s4tICommand++ {
		// Read the command
		var s1tpCommand [10]string
		fmt.Scanf("%s", &s1tpCommand)

		// Execute the command based on its type
		if s1tpCommand[0] == "insert" {
			// If the command is "insert", read the key value and insert it into the tree
			var s4tInsertKey int
			fmt.Scanf("%d", &s4tInsertKey)
			vdDInsert(&stpRoot, s4tInsertKey)
		} else {
			// If the command is "print", print the tree
			vdDPrint(stpRoot)
		}
	}
}


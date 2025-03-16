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

// Node structure
type Node struct {
	id   int
	l, r int
	par  int
}

// Global variables
var N [100000]Node
var p int

// Function to initialize the tree
func init(n int) {
	for i := 0; i < n; i++ {
		N[i].id = i
		N[i].l = -1
		N[i].r = -1
		N[i].par = -1
	}
}

// Function to perform Preorder tree traversal
func Preorder(id int) {
<<<<<<< HEAD
	fmt.Printf("%d ", N[id].id)
	if N[id].l!= -1 {
		Preorder(N[id].l)
	}
	if N[id].r!= -1 {
		Preorder(N[id].r)
	}
=======
	if id == -1 {
		return
	}
	fmt.Printf("%d ", N[id].id)
	Preorder(N[id].l)
	Preorder(N[id].r)
>>>>>>> 98c87cb78a (data updated)
}

// Function to perform Inorder tree traversal
func Inorder(id int) {
<<<<<<< HEAD
	if N[id].l!= -1 {
		Inorder(N[id].l)
	}
	fmt.Printf("%d ", N[id].id)
	if N[id].r!= -1 {
		Inorder(N[id].r)
	}
=======
	if id == -1 {
		return
	}
	Inorder(N[id].l)
	fmt.Printf("%d ", N[id].id)
	Inorder(N[id].r)
>>>>>>> 98c87cb78a (data updated)
}

// Function to perform Postorder tree traversal
func Postorder(id int) {
<<<<<<< HEAD
	if N[id].l!= -1 {
		Postorder(N[id].l)
	}
	if N[id].r!= -1 {
		Postorder(N[id].r)
	}
=======
	if id == -1 {
		return
	}
	Postorder(N[id].l)
	Postorder(N[id].r)
>>>>>>> 98c87cb78a (data updated)
	fmt.Printf("%d ", N[id].id)
}

// Function to read the input and build the tree
func readInput() {
	// Read the number of nodes in the tree
	n, _ := strconv.Atoi(readLine())

	// Initialize the tree
	init(n)

	// Read the input and build the tree
	for i := 0; i < n; i++ {
		// Read the id, left child, and right child of the current node
		line := readLine()
<<<<<<< HEAD
		id, l, r := strings.Split(line, " ")[0], strings.Split(line, " ")[1], strings.Split(line, " ")[2]
		id, l, r = strconv.Atoi(id), strconv.Atoi(l), strconv.Atoi(r)
=======
		line = strings.Split(line, " ")
		id, _ := strconv.Atoi(line[0])
		l, _ := strconv.Atoi(line[1])
		r, _ := strconv.Atoi(line[2])
>>>>>>> 98c87cb78a (data updated)

		// If the left child is not -1, assign it to the left child of the current node
		if l!= -1 {
			N[id].l = l
			N[l].par = id
		}

		// If the right child is not -1, assign it to the right child of the current node
		if r!= -1 {
			N[id].r = r
			N[r].par = id
		}
	}

	// Find the root node and perform tree traversals
	for i := 0; i < n; i++ {
		if N[i].par == -1 {
			p = i
			break
		}
	}
}

// Function to read a line from stdin
func readLine() string {
	reader := bufio.NewReader(os.Stdin)
<<<<<<< HEAD
	str, _, _ := reader.ReadLine()
	return strings.TrimRight(string(str), "\r\n")
=======
	line, _, err := reader.ReadLine()
	if err == nil {
		return string(line)
	}
	panic(err)
>>>>>>> 98c87cb78a (data updated)
}

// Main function
func main() {
	readInput()

	// Print the tree traversals in Preorder, Inorder, and Postorder
	fmt.Println("Preorder")
	Preorder(p)
	fmt.Println("")

	fmt.Println("Inorder")
	Inorder(p)
	fmt.Println("")

	fmt.Println("Postorder")
	Postorder(p)
	fmt.Println("")
}

// Comment: This is the main function that initializes the tree, reads the input, and performs the tree traversals in Preorder, Inorder, and Postorder.


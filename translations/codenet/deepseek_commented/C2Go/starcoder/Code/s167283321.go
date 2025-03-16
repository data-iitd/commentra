<<<<<<< HEAD

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)
=======
package main

import "fmt"
>>>>>>> 98c87cb78a (data updated)

// Define the structure Node
type Node struct {
	parent, left, right int
}

// Declare an array of Node structures and an integer variable n
var R [10000]Node
var n int

// Declare the traversal functions
func preorder(x int) {
	if x == -1 {
		return
	}
	fmt.Printf(" %d", x)
	preorder(R[x].left)
	preorder(R[x].right)
}

func inorder(x int) {
	if x == -1 {
		return
	}
	inorder(R[x].left)
	fmt.Printf(" %d", x)
	inorder(R[x].right)
}

func postorder(x int) {
	if x == -1 {
		return
	}
	postorder(R[x].left)
	postorder(R[x].right)
	fmt.Printf(" %d", x)
}

func main() {
	var i, a, b, c, root int
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		R[i].parent = -1
	}
	for i = 0; i < n; i++ {
		fmt.Scanf("%d %d %d", &a, &b, &c)
		R[a].left = b
		R[a].right = c
		if b!= -1 {
			R[b].parent = a
		}
		if c!= -1 {
			R[c].parent = a
		}
	}
	for i = 0; i < n; i++ {
		if R[i].parent == -1 {
			root = i
		}
	}
	fmt.Printf("Preorder\n")
	preorder(root)
	fmt.Printf("\n")
	fmt.Printf("Inorder\n")
	inorder(root)
	fmt.Printf("\n")
	fmt.Printf("Postorder\n")
	postorder(root)
	fmt.Printf("\n")
}


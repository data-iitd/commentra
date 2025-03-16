
package main

import (
	"bufio"
	"fmt"
	"os"
)

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
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var a, b, c, root int
	scanner.Scan()
	n, _ = fmt.Sscanf(scanner.Text(), "%d", &n)
	for i := 0; i < n; i++ {
		R[i].parent = -1
	}
	for i := 0; i < n; i++ {
		scanner.Scan()
		fmt.Sscanf(scanner.Text(), "%d %d %d", &a, &b, &c)
		R[a].left = b
		R[a].right = c
		if b!= -1 {
			R[b].parent = a
		}
		if c!= -1 {
			R[c].parent = a
		}
	}
	for i := 0; i < n; i++ {
		if R[i].parent == -1 {
			root = i
		}
	}
	fmt.Println("Preorder")
	preorder(root)
	fmt.Println()
	fmt.Println("Inorder")
	inorder(root)
	fmt.Println()
	fmt.Println("Postorder")
	postorder(root)
	fmt.Println()
}


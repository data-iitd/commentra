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

// BT is a node of the binary tree
type BT struct {
	parent int
	right  int
	left   int
}

var bt [26]BT
var n int

// Preorder traverses the binary tree in preorder
func Preorder(a int) {
	if a == -1 {
		return
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	fmt.Printf(" %d", a)
	Preorder(bt[a].left)
	Preorder(bt[a].right)
}

// Inorder traverses the binary tree in inorder
func Inorder(a int) {
	if a == -1 {
		return
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	Inorder(bt[a].left)
	fmt.Printf(" %d", a)
	Inorder(bt[a].right)
}

// Postorder traverses the binary tree in postorder
func Postorder(a int) {
	if a == -1 {
		return
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	Postorder(bt[a].left)
	Postorder(bt[a].right)
	fmt.Printf(" %d", a)
}

func main() {
	var i, j, num int
<<<<<<< HEAD
	var s string

	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &num)
		fmt.Scanf("%d%d", &bt[num].left, &bt[num].right)
=======

	fmt.Scanf("%d", &n)

	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &num)
		fmt.Scanf("%d%d", &bt[num].left, &bt[num].right)

>>>>>>> 98c87cb78a (data updated)
		if bt[num].left!= -1 && bt[num].right!= -1 {
			bt[bt[num].left].parent = num
			bt[bt[num].right].parent = num
		} else if bt[num].left!= -1 {
			bt[bt[num].left].parent = num
		} else if bt[num].right!= -1 {
			bt[bt[num].right].parent = num
		}
	}
<<<<<<< HEAD
	for i = 0; bt[i].parent!= -1; i++ {
	}
	fmt.Printf("Preorder\n")
	Preorder(i)
	fmt.Printf("\n")
	fmt.Printf("Inorder\n")
	Inorder(i)
	fmt.Printf("\n")
=======

	for i = 0; bt[i].parent!= -1; i++ {
	}

	fmt.Printf("Preorder\n")
	Preorder(i)
	fmt.Printf("\n")

	fmt.Printf("Inorder\n")
	Inorder(i)
	fmt.Printf("\n")

>>>>>>> 98c87cb78a (data updated)
	fmt.Printf("Postorder\n")
	Postorder(i)
	fmt.Printf("\n")
}


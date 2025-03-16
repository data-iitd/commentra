
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type BT struct {
	parent int
	right  int
	left   int
}

var bt [26]BT
var n int

func Preorder(a int) {
	if a == -1 {
		return
	}

	fmt.Printf(" %d", a)
	Preorder(bt[a].left)
	Preorder(bt[a].right)
}

func Inorder(a int) {
	if a == -1 {
		return
	}

	Inorder(bt[a].left)
	fmt.Printf(" %d", a)
	Inorder(bt[a].right)
}

func Postorder(a int) {
	if a == -1 {
		return
	}

	Postorder(bt[a].left)
	Postorder(bt[a].right)
	fmt.Printf(" %d", a)
}

func main() {
	var i, j, num, depth int

	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}

	for i = 0; i < n; i++ {
		bt[i].parent = -1
	}

	for i = 0; i < n; i++ {
		if scanner.Scan() {
			num, _ = strconv.Atoi(scanner.Text())
		}
		if scanner.Scan() {
			bt[num].left, _ = strconv.Atoi(scanner.Text())
		}
		if scanner.Scan() {
			bt[num].right, _ = strconv.Atoi(scanner.Text())
		}

		if bt[num].left!= -1 && bt[num].right!= -1 {
			bt[bt[num].left].parent = num
			bt[bt[num].right].parent = num
		} else if bt[num].left!= -1 {
			bt[bt[num].left].parent = num
		} else if bt[num].right!= -1 {
			bt[bt[num].right].parent = num
		}
	}

	for i = 0; bt[i].parent!= -1; i++ {
	}

	fmt.Println("Preorder")
	Preorder(i)
	fmt.Println()

	fmt.Println("Inorder")
	Inorder(i)
	fmt.Println()

	fmt.Println("Postorder")
	Postorder(i)
	fmt.Println()
}

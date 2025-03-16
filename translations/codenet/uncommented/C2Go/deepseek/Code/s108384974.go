package main

import (
	"bufio"
	"fmt"
	"os"
)

type Node struct {
	key int
	p   *Node
	l   *Node
	r   *Node
}

var r, NIL *Node

func find(x *Node, k int) *Node {
	for x != NIL && k != x.key {
		if k < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	return x
}

func insert(k int) {
	var y *Node = NIL
	var x *Node = r

	z := &Node{key: k, l: NIL, r: NIL}

	for x != NIL {
		y = x
		if z.key < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	z.p = y

	if y == NIL {
		r = z
	} else if z.key < y.key {
		y.l = z
	} else {
		y.r = z
	}
}

func inorder(u *Node) {
	if u == NIL {
		return
	}
	inorder(u.l)
	fmt.Printf(" %d", u.key)
	inorder(u.r)
}

func preorder(u *Node) {
	if u == NIL {
		return
	}
	fmt.Printf(" %d", u.key)
	preorder(u.l)
	preorder(u.r)
}

func print() {
	inorder(r)
	fmt.Println()
	preorder(r)
	fmt.Println()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, i, z, x int
	var s string

	scanner.Scan()
	fmt.Sscan(scanner.Text(), &n)
	for i = 0; i < n; i++ {
		scanner.Scan()
		s = scanner.Text()
		if s[0] == 'f' {
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &x)
			t := find(r, x)
			if t == NIL {
				fmt.Println("no")
			} else {
				fmt.Println("yes")
			}
		} else if s[0] == 'i' {
			scanner.Scan()
			fmt.Sscan(scanner.Text(), &z)
			insert(z)
		} else {
			print()
		}
	}
}


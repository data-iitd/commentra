package main

import (
	"fmt"
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
	x := r

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
	var n, x, z int
	var s string

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s)
		if s[0] == 'f' {
			fmt.Scan(&x)
			t := find(r, x)
			if t == NIL {
				fmt.Println("no")
			} else {
				fmt.Println("yes")
			}
		} else if s[0] == 'i' {
			fmt.Scan(&z)
			insert(z)
		} else {
			print()
		}
	}
}

// <END-OF-CODE>

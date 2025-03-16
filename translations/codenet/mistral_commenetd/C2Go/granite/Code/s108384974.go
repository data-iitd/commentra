

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	key int
	p   *Node
	l   *Node
	r   *Node
}

var (
	r *Node
	nilNode *Node
)

func find(x *Node, k int) *Node {
	for x!= nilNode && k!= x.key {
		if k < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	return x
}

func insert(k int) {
	y := nilNode
	x := r
	z := &Node{key: k, l: nilNode, r: nilNode, p: nilNode}
	for x!= nilNode {
		y = x
		if k < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	z.p = y
	if y == nilNode {
		r = z
	} else if k < y.key {
		y.l = z
	} else {
		y.r = z
	}
}

func inorder(u *Node) {
	if u == nilNode {
		return
	}
	inorder(u.l)
	fmt.Printf(" %d", u.key)
	inorder(u.r)
}

func preorder(u *Node) {
	if u == nilNode {
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
	r = nilNode
	nilNode = &Node{key: 0, l: nilNode, r: nilNode, p: nilNode}
	scanner := bufio.NewScanner(os.Stdin)
	var n, i, j, z, x int
	var s string
	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&s)
		if s[0] == 'f' {
			fmt.Scan(&x)
			t := find(r, x)
			if t == nilNode {
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


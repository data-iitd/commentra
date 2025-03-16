
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

var r *Node
var NIL *Node

func find(x *Node, k int) *Node {
	for x!= NIL && k!= x.key {
		if k < x.key {
			x = x.l
		} else {
			x = x.r
		}
	}
	return x
}

func insert(k int) {
	y := NIL
	x := r
	z := &Node{key: k, l: NIL, r: NIL, p: NIL}
	for x!= NIL {
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
	data, _ := os.Open(os.Args[1])
	defer data.Close()
	scanner := bufio.NewScanner(data)
	for scanner.Scan() {
		line := scanner.Text()
		fields := strings.Fields(line)
		if fields[0] == "find" {
			x, _ := strconv.Atoi(fields[1])
			t := find(r, x)
			if t == NIL {
				fmt.Println("no")
			} else {
				fmt.Println("yes")
			}
		} else if fields[0] == "insert" {
			z, _ := strconv.Atoi(fields[1])
			insert(z)
		} else {
			print()
		}
	}
}

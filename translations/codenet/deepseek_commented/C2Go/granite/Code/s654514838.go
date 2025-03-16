
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

var NIL *Node

func find(p *Node, x int) bool {
	for p!= NIL {
		if p.key == x {
			return true
		} else if p.key > x {
			p = p.left
		} else {
			p = p.right
		}
	}
	return false
}

func inorder(p *Node) {
	if p.left!= NIL {
		inorder(p.left)
	}
	fmt.Printf(" %d", p.key)
	if p.right!= NIL {
		inorder(p.right)
	}
}

func preorder(p *Node) {
	fmt.Printf(" %d", p.key)
	if p.left!= NIL {
		preorder(p.left)
	}
	if p.right!= NIL {
		preorder(p.right)
	}
}

func print(p *Node) {
	inorder(p)
	fmt.Println()
	preorder(p)
	fmt.Println()
}

func makeNode(x, y int) *Node {
	new := &Node{key: x, priority: y, left: NIL, right: NIL}
	return new
}

func rightRotate(p *Node) *Node {
	q := p.left
	p.left = q.right
	q.right = p
	return q
}

func leftRotate(p *Node) *Node {
	q := p.right
	p.right = q.left
	q.left = p
	return q
}

func insert(t **Node, key, priority int) *Node {
	if *t == NIL {
		return makeNode(key, priority)
	}
	if (*t).key == key {
		return *t
	}
	if key < (*t).key {
		(*t).left = insert(&(*t).left, key, priority)
		if (*t).priority < (*t).left.priority {
			*t = rightRotate(*t)
		}
	} else {
		(*t).right = insert(&(*t).right, key, priority)
		if (*t).priority < (*t).right.priority {
			*t = leftRotate(*t)
		}
	}
	return *t
}

func Delete(t **Node, key int) *Node {
	if *t == NIL {
		return NIL
	}
	if key < (*t).key {
		(*t).left = Delete(&(*t).left, key)
	} else if key > (*t).key {
		(*t).right = Delete(&(*t).right, key)
	} else {
		return delete(t, key)
	}
	return *t
}

func delete(t **Node, key int) *Node {
	if (*t).left == NIL && (*t).right == NIL {
		return NIL
	} else if (*t).left == NIL {
		*t = leftRotate(*t)
	} else if (*t).right == NIL {
		*t = rightRotate(*t)
	} else {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	return Delete(t, key)
}

func main() {
	var num int
	var x, y int
	var com string
	var root *Node = NIL
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		num, _ = strconv.Atoi(scanner.Text())
	}
	for i := 0; i < num; i++ {
		if scanner.Scan() {
			com = scanner.Text()
		}
		switch com[0] {
		case 'i':
			if scanner.Scan() {
				x, _ = strconv.Atoi(strings.Split(scanner.Text(), " ")[0])
			}
			if scanner.Scan() {
				y, _ = strconv.Atoi(strings.Split(scanner.Text(), " ")[1])
			}
			root = insert(&root, x, y)
		case 'd':
			if scanner.Scan() {
				x, _ = strconv.Atoi(scanner.Text())
			}
			root = Delete(&root, x)
		case 'f':
			if scanner.Scan() {
				x, _ = strconv.Atoi(scanner.Text())
			}
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		case 'p':
			print(root)
		}
	}
}


package main

import (
	"fmt"
)

type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

func find(p *Node, x int) bool {
	for p != nil {
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

func inorder(a *Node) {
	if a != nil {
		inorder(a.left)
		fmt.Printf(" %d", a.key)
		inorder(a.right)
	}
}

func preorder(p *Node) {
	if p != nil {
		fmt.Printf(" %d", p.key)
		preorder(p.left)
		preorder(p.right)
	}
}

func print(p *Node) {
	inorder(p)
	fmt.Println()
	preorder(p)
	fmt.Println()
}

func makenode(x, y int) *Node {
	return &Node{key: x, priority: y, left: nil, right: nil}
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
	if *t == nil {
		return makenode(key, priority)
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
	if *t == nil {
		return nil
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
	if (*t).left == nil && (*t).right == nil {
		return nil
	} else if (*t).left == nil {
		*t = leftRotate(*t)
	} else if (*t).right == nil {
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
	var num, x, y int
	var command string
	var root *Node

	fmt.Scan(&num)

	for i := 0; i < num; i++ {
		fmt.Scan(&command)
		switch command[0] {
		case 'i':
			fmt.Scan(&x, &y)
			root = insert(&root, x, y)
		case 'd':
			fmt.Scan(&x)
			root = Delete(&root, x)
		case 'f':
			fmt.Scan(&x)
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

// <END-OF-CODE>

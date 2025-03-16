package main

import "fmt"

type Node struct {
	key      int
	priority int
	left     *Node
	right    *Node
}

func find(p *Node, x int) bool {
	for p!= nil {
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
	if a.left!= nil {
		inorder(a.left)
	}
	fmt.Printf(" %d", a.key)
	if a.right!= nil {
		inorder(a.right)
	}
	return
}

func preorder(p *Node) {
	fmt.Printf(" %d", p.key)
	if p.left!= nil {
		preorder(p.left)
	}
	if p.right!= nil {
		preorder(p.right)
	}
	return
}

func print(p *Node) {
	inorder(p)
	fmt.Printf("\n")
	preorder(p)
	fmt.Printf("\n")
	return
}

func makenode(x, y int) *Node {
	new := new(Node)
	new.key = x
	new.priority = y
	new.left = nil
	new.right = nil
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
	var new *Node
	if *t == nil {
		return new = makenode(key, priority)
	}
	if (*t).key == key {
		return *t
	}
	if key < (*t).key {
		(*t).left = insert(&(*t).left, key, priority)
		if (*t).priority < (*t).left.priority {
			(*t) = rightRotate(*t)
		}
	} else {
		(*t).right = insert(&(*t).right, key, priority)
		if (*t).priority < (*t).right.priority {
			(*t) = leftRotate(*t)
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
		(*t) = leftRotate(*t)
	} else if (*t).right == nil {
		(*t) = rightRotate(*t)
	} else {
		if (*t).left.priority > (*t).right.priority {
			(*t) = rightRotate(*t)
		} else {
			(*t) = leftRotate(*t)
		}
	}
	return Delete(t, key)
}

func main() {
	var num, x, y int
	var com [8]byte
	var root *Node = nil
	fmt.Scanf("%d", &num)
	for i := 0; i < num; i++ {
		fmt.Scanf("%s", &com)
		switch com[0] {
		case 'i':
			fmt.Scanf("%d %d", &x, &y)
			root = insert(&root, x, y)
			break
		case 'd':
			fmt.Scanf("%d", &x)
			root = Delete(&root, x)
			break
		case 'f':
			fmt.Scanf("%d", &x)
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
			break
		case 'p':
			print(root)
			break
		}
	}
}


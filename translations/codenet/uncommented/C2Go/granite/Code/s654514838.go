
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
		*t = rightRotate(*t)
	} else if (*t).right == NIL {
		*t = leftRotate(*t)
	} else {
		if (*t).left.priority > (*t).right.priority {
			*t = rightRotate(*t)
		} else {
			*t = leftRotate(*t)
		}
	}
	return Delete(t, key)
}

func find(x *Node, key int) bool {
	for x!= NIL {
		if x.key == key {
			return true
		} else if x.key > key {
			x = x.left
		} else {
			x = x.right
		}
	}
	return false
}

func inorder(t *Node) {
	if t.left!= NIL {
		inorder(t.left)
	}
	fmt.Printf(" %d", t.key)
	if t.right!= NIL {
		inorder(t.right)
	}
}

func preorder(t *Node) {
	fmt.Printf(" %d", t.key)
	if t.left!= NIL {
		preorder(t.left)
	}
	if t.right!= NIL {
		preorder(t.right)
	}
}

func print(t *Node) {
	inorder(t)
	fmt.Println()
	preorder(t)
	fmt.Println()
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	const initialBufSize = 4096
	const maxBufSize = 1000000
	scanner.Buffer(make([]byte, initialBufSize), maxBufSize)
	scanner.Split(bufio.ScanWords)
	var n int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	var root *Node = NIL
	for i := 0; i < n; i++ {
		scanner.Scan()
		s := scanner.Text()
		if s[0] == 'i' {
			var x, y int
			scanner.Scan()
			x, _ = strconv.Atoi(scanner.Text())
			scanner.Scan()
			y, _ = strconv.Atoi(scanner.Text())
			root = insert(&root, x, y)
		} else if s[0] == 'd' {
			var x int
			scanner.Scan()
			x, _ = strconv.Atoi(scanner.Text())
			root = Delete(&root, x)
		} else if s[0] == 'f' {
			var x int
			scanner.Scan()
			x, _ = strconv.Atoi(scanner.Text())
			if find(root, x) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if s[0] == 'p' {
			print(root)
		}
	}
}

func insert(t **Node, key, priority int) *Node {
	if *t == NIL {
		return &Node{key, priority, NIL, NIL}
	}
	if key < (*t).key {
		(*t).left = insert(&(*t).left, key, priority)
		if (*t).priority < (*t).left.priority {
			*t = rightRotate(*t)
		}
	} else if key > (*t).key {
		(*t).right = insert(&(*t).right, key, priority)
		if (*t).priority < (*t).right.priority {
			*t = leftRotate(*t)
		}
	}
	return *t
}

func leftRotate(t **Node) *Node {
	s := (*t).right
	(*t).right = s.left
	s.left = *t
	*t = s
	return *t
}

func rightRotate(t **Node) *Node {
	s := (*t).left
	(*t).left = s.right
	s.right = *t
	*t = s
	return *t
}

// 
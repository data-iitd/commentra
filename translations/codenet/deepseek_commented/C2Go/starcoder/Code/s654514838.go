<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

// Node is a node in the tree
type Node struct {
	Key      int
	Priority int
	Left     *Node
	Right    *Node
}

// Nil is a pointer to a nil node
<<<<<<< HEAD
var Nil = &Node{}
=======
var Nil = &Node{math.MinInt32, math.MinInt32, nil, nil}
>>>>>>> 98c87cb78a (data updated)

// Delete deletes a node from the tree
func Delete(t *Node, key int) *Node {
	if t == Nil {
		return Nil
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	if key < t.Key {
		t.Left = Delete(t.Left, key)
	} else if key > t.Key {
		t.Right = Delete(t.Right, key)
	} else {
		if t.Left == Nil {
			return t.Right
<<<<<<< HEAD
		}
		if t.Right == Nil {
			return t.Left
		}
		// find the successor
		s := t.Right
		for s.Left!= Nil {
			s = s.Left
		}
		t.Key = s.Key
		t.Right = Delete(t.Right, s.Key)
=======
		} else if t.Right == Nil {
			return t.Left
		} else {
			// find the successor
			s := t.Right
			for s.Left!= Nil {
				s = s.Left
			}
			t.Key = s.Key
			t.Priority = s.Priority
			t.Right = Delete(t.Right, s.Key)
		}
>>>>>>> 98c87cb78a (data updated)
	}
	return t
}

<<<<<<< HEAD
// Find returns true if the key is in the tree
func Find(t *Node, key int) bool {
	if t == Nil {
		return false
	}
	if key < t.Key {
		return Find(t.Left, key)
	} else if key > t.Key {
		return Find(t.Right, key)
	}
	return true
}

=======
>>>>>>> 98c87cb78a (data updated)
// Insert inserts a new node into the tree
func Insert(t *Node, key, priority int) *Node {
	if t == Nil {
		return &Node{key, priority, Nil, Nil}
	}
<<<<<<< HEAD
=======

>>>>>>> 98c87cb78a (data updated)
	if key < t.Key {
		t.Left = Insert(t.Left, key, priority)
	} else if key > t.Key {
		t.Right = Insert(t.Right, key, priority)
	} else {
		t.Priority = priority
	}
<<<<<<< HEAD
	return t
}

// Inorder traverses the tree in order
func Inorder(t *Node) {
	if t!= Nil {
		Inorder(t.Left)
		fmt.Printf(" %d", t.Key)
		Inorder(t.Right)
	}
}

// Preorder traverses the tree in preorder
func Preorder(t *Node) {
	if t!= Nil {
		fmt.Printf(" %d", t.Key)
		Preorder(t.Left)
		Preorder(t.Right)
=======

	if t.Priority < t.Left.Priority {
		t = RotateRight(t)
	} else if t.Priority < t.Right.Priority {
		t = RotateLeft(t)
	}

	return t
}

// RotateLeft rotates a node to the left
func RotateLeft(t *Node) *Node {
	r := t.Right
	t.Right = r.Left
	r.Left = t
	return r
}

// RotateRight rotates a node to the right
func RotateRight(t *Node) *Node {
	l := t.Left
	t.Left = l.Right
	l.Right = t
	return l
}

// Find searches for a node in the tree
func Find(t *Node, key int) bool {
	if t == Nil {
		return false
	}

	if key < t.Key {
		return Find(t.Left, key)
	} else if key > t.Key {
		return Find(t.Right, key)
	} else {
		return true
>>>>>>> 98c87cb78a (data updated)
	}
}

// Print prints the tree
func Print(t *Node) {
<<<<<<< HEAD
	Inorder(t)
	fmt.Printf("\n")
	Preorder(t)
	fmt.Printf("\n")
}

// RightRotate performs a right rotation on the given node
func RightRotate(t *Node) *Node {
	q := t.Left
	t.Left = q.Right
	q.Right = t
	return q
}

// LeftRotate performs a left rotation on the given node
func LeftRotate(t *Node) *Node {
	q := t.Right
	t.Right = q.Left
	q.Left = t
	return q
}

// main is the entry point of the program
=======
	if t == Nil {
		return
	}

	Print(t.Left)
	fmt.Printf("%d %d\n", t.Key, t.Priority)
	Print(t.Right)
}

// Main is the entry point of the program
>>>>>>> 98c87cb78a (data updated)
func main() {
	var t *Node
	var key, priority int
	var com string
<<<<<<< HEAD
	var num int
	fmt.Scanf("%d", &num)
	for i := 0; i < num; i++ {
		fmt.Scanf("%s", &com)
		switch com[0] {
		case 'i':
			fmt.Scanf("%d %d", &key, &priority)
			t = Insert(t, key, priority)
		case 'd':
			fmt.Scanf("%d", &key)
			t = Delete(t, key)
		case 'f':
			fmt.Scanf("%d", &key)
			if Find(t, key) {
				fmt.Printf("yes\n")
			} else {
				fmt.Printf("no\n")
			}
		case 'p':
=======

	// read the number of commands
	num, _ := strconv.Atoi(os.Args[1])

	// read the commands
	for i := 0; i < num; i++ {
		com = strings.Split(os.Args[2+i], " ")[0]
		key, _ = strconv.Atoi(strings.Split(os.Args[2+i], " ")[1])
		if com == "i" {
			priority, _ = strconv.Atoi(strings.Split(os.Args[2+i], " ")[2])
			t = Insert(t, key, priority)
		} else if com == "d" {
			t = Delete(t, key)
		} else if com == "f" {
			if Find(t, key) {
				fmt.Println("yes")
			} else {
				fmt.Println("no")
			}
		} else if com == "p" {
>>>>>>> 98c87cb78a (data updated)
			Print(t)
		}
	}
}


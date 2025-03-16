package main

import (
	"fmt"
	"strings"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var head *Node

func makeNode(a int) *Node {
	return &Node{key: a}
}

func insert(a int) {
	x := makeNode(a)
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

func deleteNode(a int) {
	x := head
	for x.next != head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next
			x.next.prev = x.prev
			break
		}
	}
}

func deleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
}

func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
}

func main() {
	var n, a int
	var op string

	head = makeNode(0)
	head.next = head
	head.prev = head

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&op)
		if op == "insert" {
			fmt.Scan(&a)
			insert(a)
		} else if op == "delete" {
			fmt.Scan(&a)
			deleteNode(a)
		} else if op == "deleteFirst" {
			deleteFirst()
		} else if op == "deleteLast" {
			deleteLast()
		}
	}

	x := head
	var result []string
	for x.next != head {
		x = x.next
		result = append(result, fmt.Sprintf("%d", x.key))
	}
	fmt.Println(strings.Join(result, " "))
}

// <END-OF-CODE>

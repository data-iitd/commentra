package main

import (
	"fmt"
	"strings"
)

type node struct {
	key  int
	next *node
	prev *node
}

var head *node

func makenode(a int) *node {
	return &node{key: a}
}

func insert(a int) {
	x := makenode(a)
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

func delete(a int) {
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
	var n int
	var op string
	var x *node

	head = makenode(0)
	head.next = head
	head.prev = head

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&op)
		if strings.EqualFold(op, "insert") {
			var a int
			fmt.Scan(&a)
			insert(a)
		} else if strings.EqualFold(op, "delete") {
			var a int
			fmt.Scan(&a)
			delete(a)
		} else if strings.EqualFold(op, "deleteFirst") {
			deleteFirst()
		} else if strings.EqualFold(op, "deleteLast") {
			deleteLast()
		}
	}

	x = head
	for x.next != head {
		fmt.Print(x.next.key)
		x = x.next
		if x.next != head {
			fmt.Print(" ")
		}
	}
	fmt.Println()
}


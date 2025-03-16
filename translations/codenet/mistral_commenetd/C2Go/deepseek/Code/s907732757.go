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

var head *node = nil

func makenode(a int) *node {
	x := &node{key: a}
	return x
}

func init() {
	head = makenode(0)
	head.next = head
	head.prev = head
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
			prev := x.prev
			prev.next = x.next
			x.next.prev = prev
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
	x := head
	for x.next != head {
		x = x.next
	}
	prev := x.prev
	prev.next = nil
}

func main() {
	var n int
	var op string
	var a int
	var x *node

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&op)
		if strings.EqualFold(op, "insert") {
			fmt.Scan(&a)
			insert(a)
		} else if strings.EqualFold(op, "delete") {
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
		fmt.Printf("%d ", x.next.key)
		x = x.next
	}
	fmt.Println()
}


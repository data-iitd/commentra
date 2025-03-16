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

type NodePointer *Node

var N NodePointer

func initList() {
	N = &Node{}
	N.next = N
	N.prev = N
}

func printList() {
	cur := N.next
	snl := 1
	var keys []string
	for cur != N {
		if snl == 0 {
			keys = append(keys, " ")
		}
		keys = append(keys, fmt.Sprintf("%d", cur.key))
		cur = cur.next
		snl = 0
	}
	fmt.Println(strings.Join(keys, ""))
}

func deleteFirst() {
	t := N.next
	N.next = t.next
	t.next.prev = N
}

func deleteLast() {
	delnode := N.prev
	N.prev = delnode.prev
	delnode.prev.next = N
}

func delete(skey int) {
	var judge int
	var t, n NodePointer

	for n = N.next; n != N; n = n.next {
		if n.key == skey {
			judge = 1
		}
	}

	if judge == 1 {
		n = N.next
		for n != N {
			if n.key == skey {
				break
			}
			n = n.next
		}
		t = n.prev
		t.next = n.next
		t.next.prev = t
	}
}

func insert(skey int) {
	newNode := &Node{key: skey}
	staticCount := 0

	if staticCount == 0 {
		newNode.next = N
		N.next = newNode
		newNode.prev = N
		N.prev = newNode
		staticCount++
	} else {
		newNode.next = N.next
		N.next.prev = newNode
		N.next = newNode
		newNode.prev = N
		staticCount++
	}
}

func main() {
	var key, n int
	var command string

	fmt.Scan(&n)
	initList()
	for i := 0; i < n; i++ {
		fmt.Scan(&command)
		if command == "insert" {
			fmt.Scan(&key)
			insert(key)
		} else if command == "deleteFirst" {
			deleteFirst()
		} else if command == "deleteLast" {
			deleteLast()
		} else {
			fmt.Scan(&key)
			delete(key)
		}
	}
	printList()
}

// <END-OF-CODE>

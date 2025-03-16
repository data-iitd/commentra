package main

import (
	"fmt"
	"strings"
)

type Node struct {
	key  uint
	next *Node
	prev *Node
}

var nilNode *Node

func listSearch(key int) *Node {
	cur := nilNode.next
	for cur != nilNode && cur.key != uint(key) {
		cur = cur.next
	}
	return cur
}

func initList() {
	nilNode = &Node{}
	nilNode.next = nilNode
	nilNode.prev = nilNode
}

func printList() {
	cur := nilNode.next
	isFirst := true
	for {
		if cur == nilNode {
			break
		}
		if !isFirst {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isFirst = false
	}
	fmt.Println()
}

func deleteNode(t *Node) {
	t.prev.next = t.next
	t.next.prev = t.prev
}

func deleteFirst() {
	t := nilNode.next
	if t == nilNode {
		return
	}
	deleteNode(t)
}

func deleteLast() {
	t := nilNode.prev
	if t == nilNode {
		return
	}
	deleteNode(t)
}

func delete(key int) {
	t := listSearch(key)
	if t == nilNode {
		return
	}
	deleteNode(t)
}

func insert(key int) {
	x := &Node{key: uint(key)}
	x.next = nilNode.next
	nilNode.next.prev = x
	nilNode.next = x
	x.prev = nilNode
}

func main() {
	var n, key int
	var command string

	fmt.Scan(&n)
	initList()

	for i := 0; i < n; i++ {
		fmt.Scan(&command, &key)

		if command[0] == 'i' {
			insert(key)
		} else if command[0] == 'd' {
			if len(command) > 6 {
				if command[6] == 'F' {
					deleteFirst()
				} else if command[6] == 'L' {
					deleteLast()
				}
			} else {
				delete(key)
			}
		}
	}

	printList()
}

// <END-OF-CODE>

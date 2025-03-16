package main

import (
	"fmt"
	"strconv"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var nil *Node

func listSearch(key int) *Node {
	cur := nil.next
	for cur != nil {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

func init() {
	nil = &Node{}
	nil.next = nil
	nil.prev = nil
}

func printList() {
	cur := nil.next
	isf := 1
	for {
		if cur == nil {
			break
		}
		if isf == 0 {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		isf = 0
	}
	fmt.Println()
}

func deleteNode(t *Node) {
	if t == nil {
		return
	}
	t.prev.next = t.next
	t.next.prev = t.prev
}

func deleteFirst() {
	t := nil.next
	if t == nil {
		return
	}
	deleteNode(t)
}

func deleteLast() {
	t := nil.prev
	if t == nil {
		return
	}
	deleteNode(t)
}

func deleteKey(key int) {
	t := listSearch(key)
	if t != nil {
		deleteNode(t)
	}
}

func insert(key int) {
	x := &Node{key: key}
	x.prev = nil
	x.next = nil.next
	x.next.prev = x
	nil.next = x
}

func main() {
	var key int
	var n, i int
	var com string
	var size int
	var np, nd int

	fmt.Scan(&n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key)
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6:] == "F" {
					deleteFirst()
				} else if com[6:] == "L" {
					deleteLast()
				}
			} else {
				deleteKey(key)
				nd++
			}
			size--
		}
	}

	printList()
}


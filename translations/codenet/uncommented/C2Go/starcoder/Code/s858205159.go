package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Node struct {
	key  int
	next *Node
	prev *Node
}

var nil = &Node{0, nil, nil}

func listSearch(key int) *Node {
	cur := nil.next
	for cur!= nil {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

func init() {
	nil.next = nil
	nil.prev = nil
}

func printList() {
	cur := nil.next
	isf := true
	for cur!= nil {
		if isf == false {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.key)
		cur = cur.next
		isf = false
	}
	fmt.Printf("\n")
}

func deleteNode(t *Node) {
	if t == nil {
		return
	}
	t.prev.next = t.next
	t.next.prev = t.prev
	free(t)
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
	if t!= nil {
		deleteNode(t)
	}
}

func insert(key int) {
	x := new(Node)
	x.key = key
	x.prev = nil
	x.next = nil.next
	x.next.prev = x
	nil.next = x
}

func main() {
	var key, n, i int
	var com string
	var np, nd int
	var size int
	fmt.Scanf("%d", &n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scanf("%s%d", &com, &key)
		if com[0] == 'i' {
			insert(key)
			np++
			size++
		} else if com[0] == 'd' {
			if len(com) > 6 {
				if com[6] == 'F' {
					deleteFirst()
				} else if com[6] == 'L' {
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


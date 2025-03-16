
package main

import (
	"bufio"
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

var nilNode *Node

func main() {
	var n int
	var size int = 0
	var np int = 0
	var nd int = 0
	var com string
	var key int
	var i int

	fmt.Scan(&n)

	nilNode = &Node{}
	nilNode.next = nilNode
	nilNode.prev = nilNode

	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key)

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
				delete(key)
			}
			nd++
			size--
		}
	}

	printList()
}

func listSearch(key int) *Node {
	cur := nilNode.next
	for cur!= nilNode && cur.key!= key {
		cur = cur.next
	}
	return cur
}

func init() {
	nilNode = &Node{}
	nilNode.next = nilNode
	nilNode.prev = nilNode
}

func printList() {
	cur := nilNode.next
	isf := true
	for {
		if cur == nilNode {
			break
		}
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
	x := &Node{}
	x.key = key
	x.next = nilNode.next
	nilNode.next.prev = x
	nilNode.next = x
	x.prev = nilNode
}

// END-OF-CODE
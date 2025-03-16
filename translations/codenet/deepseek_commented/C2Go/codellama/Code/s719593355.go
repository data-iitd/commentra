
package main

import "fmt"

type Node struct {
	key  int
	next *Node
	prev *Node
}

var nil *Node

func init() {
	nil = &Node{0, nil, nil}
	nil.next = nil
	nil.prev = nil
}

func listSearch(key int) *Node {
	cur := nil.next
	for cur != nil && cur.key != key {
		cur = cur.next
	}
	return cur
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
		fmt.Printf("%d", cur.key)
		cur = cur.next
		isf = 0
	}
	fmt.Println()
}

func deleteNode(t *Node) {
	t.prev.next = t.next
	t.next.prev = t.prev
	t = nil
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

func delete(key int) {
	t := listSearch(key)
	if t == nil {
		return
	}
	deleteNode(t)
}

func insert(key int) {
	x := &Node{key, nil, nil}
	x.next = nil.next
	nil.next.prev = x
	nil.next = x
	x.prev = nil
}

func main() {
	var key, n, i int
	var size int
	var np, nd int
	var com string
	fmt.Scan(&n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scan(&com, &key)
		if com == "i" {
			insert(key)
			np++
			size++
		} else if com == "d" {
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


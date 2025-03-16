package main

import "fmt"

type Node struct {
	key int
	next *Node
	prev *Node
}

var N *Node

func init() {
	N = &Node{next: N, prev: N}
}

func printList() {
	cur := N.next
	snl := 1
	for cur != N {
		if snl == 0 {
			fmt.Print(" ")
		}
		fmt.Print(cur.key)
		cur = cur.next
		snl = 0
	}
	fmt.Println()
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
	judge := 0
	var t *Node
	var n *Node

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
	var new *Node
	var count int
	new = &Node{key: skey}
	if count == 0 {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
		count++
	} else {
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
		count++
	}
}

func main() {
	var key, n, i int
	var com string
	fmt.Scan(&n)
	init()
	for i = 0; i < n; i++ {
		fmt.Scan(&com)
		if com == "insert" {
			fmt.Scan(&key)
			insert(key)
		} else if com == "deleteFirst" {
			deleteFirst()
		} else if com == "deleteLast" {
			deleteLast()
		} else {
			fmt.Scan(&key)
			delete(key)
		}
	}
	printList()
}


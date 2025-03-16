
package main

import "fmt"

type Node struct {
	key int
	next *Node
	prev *Node
}

var head *Node

func MakeNode(a int) *Node {
	x := new(Node)
	x.key = a
	return x
}

func Insert(a int) {
	x := MakeNode(a)
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

func Delete(a int) {
	x := head
	for x.next != head {
		x = x.next
		if x.key == a {
			x.prev.next = x.next
			x.next.prev = x.prev
			x = nil
			break
		}
	}
}

func DeleteFirst() {
	x := head.next
	head.next = x.next
	x.next.prev = head
	x = nil
}

func DeleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
	x = nil
}

func main() {
	var i, n, a int
	var op string
	var x *Node

	head = MakeNode(0)
	head.next = head
	head.prev = head

	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%s", &op)
		if op == "insert" {
			fmt.Scanf("%d", &a)
			Insert(a)
		} else if op == "delete" {
			fmt.Scanf("%d", &a)
			Delete(a)
		} else if op == "deleteFirst" {
			DeleteFirst()
		} else if op == "deleteLast" {
			DeleteLast()
		}
	}

	x = head
	for x.next != head {
		fmt.Printf("%d", x.next.key)
		x = x.next
		if x.next != head {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
}


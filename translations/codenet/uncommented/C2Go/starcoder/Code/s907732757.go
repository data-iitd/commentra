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

func main() {
	head := &Node{0, nil, nil}
	head.next = head
	head.prev = head

	n, _ := strconv.Atoi(os.Args[1])
	for i := 0; i < n; i++ {
		op := strings.Split(os.Args[2+i], " ")
		if op[0] == "insert" {
			a, _ := strconv.Atoi(op[1])
			insert(a)
		} else if op[0] == "delete" {
			a, _ := strconv.Atoi(op[1])
			delete(a)
		} else if op[0] == "deleteFirst" {
			deleteFirst()
		} else if op[0] == "deleteLast" {
			deleteLast()
		}
	}

	x := head
	for x.next!= head {
		fmt.Printf("%d", x.next.key)
		x = x.next
		if x.next!= head {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
}

func insert(a int) {
	x := &Node{a, nil, nil}
	x.next = head.next
	head.next.prev = x
	head.next = x
	x.prev = head
}

func delete(a int) {
	x := head
	for x.next!= head {
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
	free(x)
}

func deleteLast() {
	x := head.prev
	head.prev = x.prev
	x.prev.next = head
	free(x)
}


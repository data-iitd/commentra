
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

func listSearch(key int) *Node {
	cur := nilNode.next
	for cur!= nilNode {
		if cur.key == key {
			break
		}
		cur = cur.next
	}
	return cur
}

func init() {
	nilNode = &Node{key: 0, next: nil, prev: nil}
}

func printList() {
	cur := nilNode.next
	isf := true
	for cur!= nilNode {
		if isf {
			fmt.Printf("%d", cur.key)
			isf = false
		} else {
			fmt.Printf(" %d", cur.key)
		}
		cur = cur.next
	}
	fmt.Println()
}

func deleteNode(t *Node) {
	if t == nilNode {
		return
	}
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

func deleteKey(key int) {
	t := listSearch(key)
	if t!= nilNode {
		deleteNode(t)
	}
}

func insert(key int) {
	x := &Node{key: key, next: nil, prev: nil}
	x.prev = nilNode
	x.next = nilNode.next
	x.next.prev = x
	nilNode.next = x
}

func main() {
	var key, n, i int
	var size, np, nd int
	var com string
	var line string
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		n, _ = strconv.Atoi(scanner.Text())
	}
	init()
	for i = 0; i < n; i++ {
		if scanner.Scan() {
			line = scanner.Text()
			com = strings.Split(line, " ")[0]
			key, _ = strconv.Atoi(strings.Split(line, " ")[1])
			if com == "insert" {
				insert(key)
				np++
				size++
			} else if com == "delete" {
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
	}
	printList()
}

// END-OF-CODE
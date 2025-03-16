
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
	x := &Node{}
	x.key = key
	x.prev = nilNode
	x.next = nilNode.next
	x.next.prev = x
	nilNode.next = x
}

func main() {
	var key, n, i int
	var size, np, nd int
	var com string
	var err error
	var line string
	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		line = scanner.Text()
		n, err = strconv.Atoi(line)
		if err!= nil {
			panic(err)
		}
	}
	init()
	for i = 0; i < n; i++ {
		if scanner.Scan() {
			line = scanner.Text()
			fields := strings.Fields(line)
			com = fields[0]
			key, err = strconv.Atoi(fields[1])
			if err!= nil {
				panic(err)
			}
			if com == "insert" {
				insert(key)
				np++
				size++
			} else if com == "delete" {
				if len(fields) > 2 {
					if fields[2] == "First" {
						deleteFirst()
					} else if fields[2] == "Last" {
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

// 
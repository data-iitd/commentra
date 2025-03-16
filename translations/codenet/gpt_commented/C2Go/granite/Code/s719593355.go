
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
	reader := bufio.NewReader(os.Stdin)
	n, _ := strconv.Atoi(strings.TrimSpace(readLine(reader)))
	list := &List{}
	list.Init()
	for i := 0; i < n; i++ {
		op := readLine(reader)
		if strings.HasPrefix(op, "insert") {
			key, _ := strconv.Atoi(strings.TrimSpace(strings.Split(op, " ")[1]))
			list.Insert(key)
		} else if strings.HasPrefix(op, "delete") {
			key, _ := strconv.Atoi(strings.TrimSpace(strings.Split(op, " ")[1]))
			list.Delete(key)
		}
	}
	list.Print()
}

func readLine(reader *bufio.Reader) string {
	str, _, err := reader.ReadLine()
	if err == nil {
		return string(str)
	}
	return ""
}

type List struct {
	head *Node
	tail *Node
}

func (list *List) Init() {
	nilNode = &Node{key: -1}
	list.head = nilNode
	list.tail = nilNode
}

func (list *List) Print() {
	cur := list.head.next
	for cur!= nilNode {
		fmt.Printf("%d ", cur.key)
		cur = cur.next
	}
	fmt.Println()
}

func (list *List) Insert(key int) {
	node := &Node{key: key}
	node.next = list.head.next
	node.prev = list.head
	list.head.next.prev = node
	list.head.next = node
}

func (list *List) Delete(key int) {
	cur := list.head.next
	for cur!= nilNode {
		if cur.key == key {
			cur.prev.next = cur.next
			cur.next.prev = cur.prev
			return
		}
		cur = cur.next
	}
}


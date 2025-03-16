
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
	n, _ := strconv.Atoi(read(reader))
	init()
	for i := 0; i < n; i++ {
		com, key := read2(reader)
		switch com {
		case "insert":
			insert(key)
		case "delete":
			delete(key)
		}
	}
	printList()
}

func read(reader *bufio.Reader) string {
	line, _, _ := reader.ReadLine()
	return string(line)
}

func read2(reader *bufio.Reader) (string, int) {
	line, _, _ := reader.ReadLine()
	s := strings.Split(string(line), " ")
	key, _ := strconv.Atoi(s[1])
	return s[0], key
}

func init() {
	nilNode = &Node{}
	nilNode.next = nilNode
	nilNode.prev = nilNode
}

func printList() {
	cur := nilNode.next
	for {
		if cur == nilNode {
			break
		}
		fmt.Printf("%d ", cur.key)
		cur = cur.next
	}
	fmt.Println()
}

func delete(key int) {
	t := search(key)
	if t == nilNode {
		return
	}
	deleteNode(t)
}

func deleteNode(t *Node) {
	t.prev.next = t.next
	t.next.prev = t.prev
}

func insert(key int) {
	x := &Node{key: key}
	x.next = nilNode.next
	nilNode.next.prev = x
	nilNode.next = x
	x.prev = nilNode
}

func search(key int) *Node {
	cur := nilNode.next
	for {
		if cur == nilNode {
			break
		}
		if cur.key == key {
			return cur
		}
		cur = cur.next
	}
	return nilNode
}


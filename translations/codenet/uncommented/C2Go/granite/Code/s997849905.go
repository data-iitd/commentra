
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

var N *Node

func init() {
	N = &Node{}
	N.next = N
	N.prev = N
}

func printList() {
	cur := N.next
	snl := 1
	for cur!= N {
		if snl == 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", cur.key)
		cur = cur.next
		snl = 0
	}
	fmt.Printf("\n")
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
	free(delnode)
}

func delete(skey int) {
	judge := 0
	n := N.next
	for n!= N {
		if n.key == skey {
			judge = 1
		}
		n = n.next
	}
	if judge == 1 {
		n = N.next
		for n!= N {
			if n.key == skey {
				break
			}
			n = n.next
		}
		t := n.prev
		t.next = n.next
		t.next.prev = t
		free(n)
	}
}

func insert(skey int) {
	new := &Node{}
	new.key = skey
	if N.next == N {
		new.next = N
		N.next = new
		new.prev = N
		N.prev = new
	} else {
		new.next = N.next
		N.next.prev = new
		N.next = new
		new.prev = N
	}
}

func main() {
	var key, n, i int
	var com string
	var err error
	var line string
	var args []string
	var reader *bufio.Reader
	reader = bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &n)
	init()
	for i = 0; i < n; i++ {
		line, err = reader.ReadString('\n')
		if err!= nil {
			break
		}
		args = strings.Split(line, " ")
		com = args[0]
		if com == "insert" {
			key, _ = strconv.Atoi(args[1])
			insert(key)
		} else if com == "deleteFirst" {
			deleteFirst()
		} else if com == "deleteLast" {
			deleteLast()
		} else {
			key, _ = strconv.Atoi(args[1])
			delete(key)
		}
	}
	printList()
}

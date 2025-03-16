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
	var (
		n, key int
		com    string
		head   *Node
		cur    *Node
		new    *Node
	)
	head = new(Node)
	head.next = head
	head.prev = head
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%s", &com)
		if com == "insert" {
			fmt.Scanf("%d", &key)
			new = new(Node)
			new.key = key
			new.next = head.next
			new.prev = head
			head.next.prev = new
			head.next = new
		} else if com == "deleteFirst" {
			cur = head.next
			head.next = cur.next
			cur.next.prev = head
			cur.next = nil
			cur.prev = nil
			cur = nil
			new = nil
			delete(cur)
		} else if com == "deleteLast" {
			cur = head.prev
			head.prev = cur.prev
			cur.prev.next = head
			cur.next = nil
			cur.prev = nil
			cur = nil
			new = nil
			delete(cur)
		} else {
			fmt.Scanf("%d", &key)
			cur = head.next
			for cur!= head {
				if cur.key == key {
					break
				}
				cur = cur.next
			}
			if cur!= head {
				cur.prev.next = cur.next
				cur.next.prev = cur.prev
				cur.next = nil
				cur.prev = nil
				cur = nil
				new = nil
				delete(cur)
			}
		}
	}
	cur = head.next
	for cur!= head {
		fmt.Printf("%d ", cur.key)
		cur = cur.next
	}
	fmt.Printf("\n")
}




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

var head *Node

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("Enter the number of operations:")
    n, _ := strconv.Atoi(read(reader))
    for i := 0; i < n; i++ {
        op := read(reader)
        if op == "insert" {
            fmt.Println("Enter the key value to be inserted:")
            a, _ := strconv.Atoi(read(reader))
            insert(a)
        } else if op == "delete" {
            fmt.Println("Enter the key value to be deleted:")
            a, _ := strconv.Atoi(read(reader))
            deleteNode(a)
        } else if op == "deleteFirst" {
            deleteFirst()
        } else if op == "deleteLast" {
            deleteLast()
        }
    }
    printList()
}

func read(reader *bufio.Reader) string {
    str, _ := reader.ReadString('\n')
    return strings.TrimSpace(str)
}

func initList() {
    head = &Node{key: 0}
    head.next = head
    head.prev = head
}

func insert(a int) {
    node := &Node{key: a}
    node.next = head.next
    head.next.prev = node
    head.next = node
    node.prev = head
}

func deleteNode(a int) {
    node := head
    for node.next!= head {
        node = node.next
        if node.key == a {
            prev := node.prev
            prev.next = node.next
            node.next.prev = prev
            node.next = nil
            node.prev = nil
            break
        }
    }
}

func deleteFirst() {
    second := head.next
    head.next = second.next
    second.next.prev = head
}

func deleteLast() {
    node := head
    for node.next!= head {
        node = node.next
    }
    prev := node.prev
    prev.next = nil
    head.prev = prev
}

func printList() {
    node := head.next
    for node!= head {
        fmt.Printf("%d ", node.key)
        node = node.next
    }
    fmt.Println()
}


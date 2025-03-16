
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type node struct {
    key  int
    next *node
    prev *node
}

var head *node

func main() {
    reader := bufio.NewReader(os.Stdin)
    n, _ := strconv.Atoi(read(reader))
    for i := 0; i < n; i++ {
        op := read(reader)
        if op == "insert" {
            a, _ := strconv.Atoi(read(reader))
            insert(a)
        } else if op == "delete" {
            a, _ := strconv.Atoi(read(reader))
            delete(a)
        } else if op == "deleteFirst" {
            deleteFirst()
        } else if op == "deleteLast" {
            deleteLast()
        }
    }
    x := head
    for x.next!= head {
        fmt.Print(x.next.key)
        x = x.next
        if x.next!= head {
            fmt.Print(" ")
        }
    }
    fmt.Println()
}

func insert(a int) {
    x := &node{key: a}
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
}

func deleteLast() {
    x := head.prev
    head.prev = x.prev
    x.prev.next = head
}

func read(reader *bufio.Reader) string {
    s, _ := reader.ReadString('\n')
    return strings.TrimSpace(s)
}


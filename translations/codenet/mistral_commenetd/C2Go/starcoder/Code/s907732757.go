
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
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

func init() {
    head = &node{0, nil, nil}
    head.next = head
    head.prev = head
}

func makeNode(a int) *node {
    x := new(node)
    x.key = a
    return x
}

func insert(a int) {
    x := makeNode(a)
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
            x.next = nil
            x.prev = nil
            break
        }
    }
}

func deleteFirst() {
    x := head.next
    head.next = x.next
    x.next.prev = head
    x.next = nil
    x.prev = nil
}

func deleteLast() {
    x := head
    for x.next!= head {
        x = x.next
    }
    x.prev.next = nil
    head.prev = x.prev
    x.prev = nil
}

func main() {
    var i, n, a int
    var op string
    var x *node
<<<<<<< HEAD
    fmt.Scanf("%d", &n)
    for i = 0; i < n; i++ {
        fmt.Scanf("%s", &op)
        if op == "insert" {
            fmt.Scanf("%d", &a)
            insert(a)
        } else if op == "delete" {
            fmt.Scanf("%d", &a)
=======
    var args []string
    args = os.Args[1:]
    n, _ = strconv.Atoi(args[0])
    for i = 0; i < n; i++ {
        op = args[i*2+1]
        if op == "insert" {
            a, _ = strconv.Atoi(args[i*2+2])
            insert(a)
        } else if op == "delete" {
            a, _ = strconv.Atoi(args[i*2+2])
>>>>>>> 98c87cb78a (data updated)
            delete(a)
        } else if op == "deleteFirst" {
            deleteFirst()
        } else if op == "deleteLast" {
            deleteLast()
        }
    }
    x = head
    for x.next!= head {
        fmt.Printf("%d ", x.next.key)
        x = x.next
    }
    fmt.Printf("\n")
}


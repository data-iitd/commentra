#include <stdio.h>
#include <stdlib.h>
#include <string.h>

type Node struct {
  key int
  next *Node
  prev *Node
}

var nil *Node

func listSearch(key int) *Node {
  cur := nil.next

  for cur != nil && cur.key != key {
    cur = cur.next
  }

  return cur
}

func init() {
  nil = &Node{}
  nil.next = nil
  nil.prev = nil
}

func printList() {
  cur := nil.next
  isf := 1
  for {
    if cur == nil {
      break
    }
    if isf == 0 {
      fmt.Print(" ")
    }
    fmt.Printf("%d", cur.key)
    cur = cur.next
    isf = 0
  }
  fmt.Println()
}

func deleteNode(t *Node) {
  t.prev.next = t.next
  t.next.prev = t.prev
  free(t)
}

func deleteFirst() {
  t := nil.next
  if t == nil {
    return
  }

  deleteNode(t)
}

func deleteLast() {
  t := nil.prev
  if t == nil {
    return
  }

  deleteNode(t)
}

func delete(key int) {
  t := listSearch(key)

  if t == nil {
    return
  }

  deleteNode(t)
}

func insert(key int) {
  x := &Node{}
  x.key = key

  x.next = nil.next
  nil.next.prev = x
  nil.next = x
  x.prev = nil
}

func main() {
  var key, n, i int
  var size int
  var com string
  var np, nd int

  fmt.Scanf("%d", &n)

  init()

  for i = 0; i < n; i++ {
    fmt.Scanf("%s%d", &com, &key)

    if com[0] == 'i' {
      insert(key)
      np++
      size++
    } else if com[0] == 'd' {
      if len(com) > 6 {
        if com[6] == 'F' {
          deleteFirst()
        } else if com[6] == 'L' {
          deleteLast()
        }
      } else {
        delete(key)
        nd++
      }

      size--
    }
  }

  printList()
}


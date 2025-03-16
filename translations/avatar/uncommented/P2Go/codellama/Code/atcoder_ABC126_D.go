package main

import (
    "fmt"
)

type Node struct {
    val   int
    color bool
    a     [][]int
}

func main() {
    var n int
    fmt.Scan(&n)
    nodes := make([]Node, n)
    for i := 0; i < n; i++ {
        nodes[i].val = i + 1
        nodes[i].a = make([][]int, 0)
    }
    for i := 0; i < n-1; i++ {
        var u, v, w int
        fmt.Scan(&u, &v, &w)
        node1 := &nodes[u-1]
        node2 := &nodes[v-1]
        node1.a = append(node1.a, []int{node2, w})
        node2.a = append(node2.a, []int{node1, w})
    }
    root := &nodes[0]
    root.color = true
    nodeSet := make(map[int]bool)
    var traverse func(node int, distance int)
    traverse = func(node int, distance int) {
        if nodeSet[node] {
            return
        } else {
            nodeSet[node] = true
        }
        for _, pair := range nodes[node].a {
            adjNode := pair[0]
            dis := pair[1]
            if (distance+dis)%2 == 0 {
                nodes[adjNode-1].color = root.color
            } else {
                nodes[adjNode-1].color = !root.color
            }
            traverse(adjNode, distance+dis)
        }
    }
    traverse(root.val, 0)
    for i := 0; i < n; i++ {
        if nodes[i].color {
            fmt.Println(1)
        } else {
            fmt.Println(0)
        }
    }
}




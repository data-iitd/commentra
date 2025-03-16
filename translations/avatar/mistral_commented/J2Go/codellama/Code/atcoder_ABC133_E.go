
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var N, K int
    var nodes []Node
    var patterns int64

    fmt.Scan(&N, &K)

    nodes = make([]Node, N)

    for i := 0; i < N; i++ {
        nodes[i] = Node{index: i}
    }

    for i := 0; i < N-1; i++ {
        var a, b int
        fmt.Scan(&a, &b)
        a--
        b--
        nodes[a].children = append(nodes[a].children, b)
        nodes[b].children = append(nodes[b].children, a)
    }

    nodes[0].setParent(K, -1, 0, nodes)

    for i := 0; i < N; i++ {
        patterns = (patterns * nodes[i].pattern) % 1000000007
    }

    fmt.Println(patterns)
}

type Node struct {
    pattern   int64
    index     int
    children  []int
    parent    int
}

func (n *Node) setParent(K, parent, use int, nodes []Node) {
    n.pattern = int64(K - use)
    n.parent = parent
    count := 1
    if parent != -1 {
        count++
    }
    for _, child := range n.children {
        if child == n.parent {
            continue
        }
        nodes[child].setParent(K, n.index, count, nodes)
        count++
    }
}


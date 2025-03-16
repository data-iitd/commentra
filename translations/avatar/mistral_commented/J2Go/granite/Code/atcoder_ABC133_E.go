

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type Node struct {
    pattern  int64
    index    int
    children []int
    parent   int
}

func (n *Node) setParent(K, parent, use int, nodes []*Node) {
    n.pattern = int64(K - use)
    n.parent = parent
    count := 1
    if parent!= -1 {
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

func (n *Node) solve() {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Scan()
    N, _ := strconv.Atoi(scanner.Text())
    scanner.Scan()
    K, _ := strconv.Atoi(scanner.Text())

    nodes := make([]*Node, N)
    for i := 0; i < N; i++ {
        nodes[i] = &Node{index: i}
    }

    for i := 0; i < N-1; i++ {
        scanner.Scan()
        line := strings.Split(scanner.Text(), " ")
        a, _ := strconv.Atoi(line[0])
        b, _ := strconv.Atoi(line[1])
        a--
        b--
        nodes[a].children = append(nodes[a].children, b)
        nodes[b].children = append(nodes[b].children, a)
    }

    nodes[0].setParent(K, -1, 0, nodes)

    patterns := int64(1)
    for i := 0; i < N; i++ {
        patterns = (patterns * nodes[i].pattern) % 1_000_000_007
    }

    fmt.Println(patterns)
}

func main() {
    main := &Main{}
    main.solve()
}


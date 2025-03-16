
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type Graph struct {
    nodes []int
    edges map[int][]int
}

func NewGraph(n int) *Graph {
    return &Graph{
        nodes: make([]int, n),
        edges: make(map[int][]int),
    }
}

func (g *Graph) AddEdge(u, v int) {
    g.nodes[u]++
    g.nodes[v]++
    g.edges[u] = append(g.edges[u], v)
    g.edges[v] = append(g.edges[v], u)
}

func (g *Graph) Dfs(u, c int) (int, bool) {
    if g.nodes[u] == 0 {
        return 0, false
    }
    g.nodes[u] = 0
    total := 1
    for _, v := range g.edges[u] {
        if g.nodes[v] > 0 {
            count, mujun := g.Dfs(v, 1-c)
            if mujun {
                return 0, true
            }
            total += count
        }
    }
    return total, false
}

func main() {
    scan := bufio.NewScanner(os.Stdin)
    n, _ := scan.nextInt()
    m, _ := scan.nextInt()
    g := NewGraph(n)
    for i := 0; i < m; i++ {
        u, _ := scan.nextInt()
        v, _ := scan.nextInt()
        g.AddEdge(u-1, v-1)
    }
    visited := make([]bool, n)
    color := make([]int, n)
    one := int64(0)
    bipartite := int64(0)
    count := int64(0)
    for i := 0; i < n; i++ {
        if!visited[i] {
            count++
            mujun := false
            kind, _ := g.Dfs(i, 0)
            if kind == 1 {
                one++
            } else if!mujun {
                bipartite++
            }
        }
    }
    total := one * (2*n - one) + (count - one)*(count - one) + bipartite*bipartite
    fmt.Println(total)
}

// END-OF-CODE
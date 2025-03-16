
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

type Graph struct {
    adjacencyList []int
    visited        []bool
    color          []int
    one            int64
    bipartite     int64
    count          int64
    mujun          bool
}

func (g *Graph) dfs(a, c int) int {
    if g.visited[a] {
        if g.color[a] >= 0 && g.color[a]!= c {
            g.mujun = true
        }
        return 0
    }
    g.visited[a] = true
    g.color[a] = c
    total := 1
    for _, b := range g.adjacencyList[a] {
        total += g.dfs(b, 1-c)
    }
    return total
}

func (g *Graph) run() {
    scanner := bufio.NewScanner(os.Stdin)
    if!scanner.Scan() {
        return
    }
    n, _ := strconv.Atoi(scanner.Text())
    if!scanner.Scan() {
        return
    }
    m, _ := strconv.Atoi(scanner.Text())
    g.adjacencyList = make([][]int, n)
    for i := 0; i < n; i++ {
        g.adjacencyList[i] = make([]int, 0)
    }
    for i := 0; i < m; i++ {
        if!scanner.Scan() {
            return
        }
        u, _ := strconv.Atoi(scanner.Text())
        if!scanner.Scan() {
            return
        }
        v, _ := strconv.Atoi(scanner.Text())
        g.adjacencyList[u-1] = append(g.adjacencyList[u-1], v-1)
        g.adjacencyList[v-1] = append(g.adjacencyList[v-1], u-1)
    }
    g.visited = make([]bool, n)
    g.color = make([]int, n)
    for i := 0; i < n; i++ {
        g.color[i] = -1
    }
    g.one = 0
    g.bipartite = 0
    g.count = 0
    for i := 0; i < n; i++ {
        if g.visited[i] {
            continue
        }
        g.count++
        g.mujun = false
        kind := g.dfs(i, 0)
        if kind == 1 {
            g.one++
        } else if!g.mujun {
            g.bipartite++
        }
    }
    total := g.one * (2*int64(n)-g.one)
    total += (g.count - g.one) * (g.count - g.one)
    total += g.bipartite * g.bipartite
    fmt.Println(total)
}

func main() {
    g := Graph{}
    g.run()
}

// END-OF-CODE
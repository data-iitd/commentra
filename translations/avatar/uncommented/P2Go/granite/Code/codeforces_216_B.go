
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func readInts() []int {
    scanner := bufio.NewScanner(os.Stdin)
    scanner.Split(bufio.ScanWords)
    var ints []int
    for scanner.Scan() {
        intVal, _ := strconv.Atoi(scanner.Text())
        ints = append(ints, intVal)
    }
    return ints
}

func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {
    if seen[i] {
        return 0, 0
    }
    seen[i] = true
    nodes := 1
    edges := len(g[i])
    for j := range g[i] {
        x, y := dfs(g, seen, j)
        nodes += x
        edges += y
    }
    return nodes, edges
}

func solve() bool {
    line0 := readInts()
    if len(line0)!= 2 {
        return false
    }
    n, m := line0[0], line0[1]
    g := make(map[int]map[int]bool)
    seen := make(map[int]bool)
    for i := 1; i <= n; i++ {
        g[i] = make(map[int]bool)
    }
    for _ = 0; _ < m; _++ {
        a, b := readInts()
        g[a][b] = true
        g[b][a] = true
    }
    ans := 0
    for i := 1; i <= n; i++ {
        if!seen[i] {
            nodes, edges := dfs(g, seen, i)
            if nodes > 1 && nodes%2 == 1 && 2*nodes == edges {
                ans++
            }
        }
    }
    if (n-ans)%2 == 1 {
        ans++
    }
    fmt.Println(ans)
    return true
}

func main() {
    for solve() {
    }
}


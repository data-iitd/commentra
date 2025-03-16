package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    for {
        line, err := reader.ReadString('\n')
        if err!= nil {
            break
        }
        line = strings.TrimSpace(line)
        line0 := strings.Split(line, " ")
        n, m := 0, 0
        n, _ = strconv.Atoi(line0[0])
        m, _ = strconv.Atoi(line0[1])
        g := make(map[int]map[int]bool)
        for i := 0; i < n; i++ {
            g[i+1] = make(map[int]bool)
        }
        for i := 0; i < m; i++ {
            line, err := reader.ReadString('\n')
            if err!= nil {
                break
            }
            line = strings.TrimSpace(line)
            line0 := strings.Split(line, " ")
            a, b := 0, 0
            a, _ = strconv.Atoi(line0[0])
            b, _ = strconv.Atoi(line0[1])
            g[a][b] = true
            g[b][a] = true
        }
        ans := 0
        for i := 0; i < n; i++ {
            seen := make(map[int]bool)
            if!dfs(g, seen, i+1) {
                continue
            }
            nodes, edges := dfs(g, seen, i+1)
            if nodes > 1 && nodes % 2 == 1 && 2*nodes == edges {
                ans += 1
        }
        if (n-ans) % 2 == 1 {
            ans += 1
        }
        fmt.Println(ans)
    }
}

func dfs(g map[int]map[int]bool, seen map[int]bool, i int) bool {
    if i in seen {
        return false
    }
    seen[i] = true
    nodes := 1
    edges := len(g[i])
    for j := range g[i] {
        if!dfs(g, seen, j) {
            continue
        }
        x, y := dfs(g, seen, j)
        nodes += x
        edges += y
    }
    return true
}


package main
import "fmt"
func readInts() []int {
    var line string
    fmt.Scanln(&line)
    return []int(strings.Fields(line))
}
func dfs(g map[int]map[int]bool, seen map[int]bool, i int) (int, int) {
    if i, ok := seen[i]; ok {
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
    line0 := []int{}
    if _, err := fmt.Scanln(&line0...); err!= nil {
        return false
    }
    n, m := line0[0], line0[1]
    g := make(map[int]map[int]bool)
    seen := make(map[int]bool)
    for i := 1; i <= n; i++ {
        g[i] = make(map[int]bool)
    }
    for _ := 0; _ < m; _++ {
        a, b := readInts()
        g[a][b] = true
        g[b][a] = true
    }
    ans := 0
    for i := 1; i <= n; i++ {
        if _, ok := seen[i];!ok {
            nodes, edges := dfs(g, seen, i)
            if nodes > 1 && nodes % 2 == 1 && 2 * nodes == edges {
                ans += 1
        }
    }
    if (n - ans) % 2 == 1 {
        ans += 1
    }
    fmt.Println(ans)
    return true
}
func main() {
    for solve() {
    }
}

package main
import "fmt"
func dfs(links [][]int, n, k, v, p int) (int, int) {
    heightFromLeaf := 0
    cutCount := 0
    for _, u := range links[v] {
        if u == 0 {
            continue
        }
        hgt, cut := dfs(links, n, k, u, v)
        heightFromLeaf = max(heightFromLeaf, hgt)
        cutCount += cut
    }
    heightFromLeaf += 1
    if p != 0 && heightFromLeaf == k {
        heightFromLeaf = 0
        cutCount += 1
    }
    return heightFromLeaf, cutCount
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
func main() {
    var n, k int
    fmt.Scan(&n, &k)
    links := make([][]int, n)
    for i := range links {
        links[i] = make([]int, 0)
    }
    for i := 1; i < n; i++ {
        var a int
        fmt.Scan(&a)
        a--
        links[a] = append(links[a], i)
    }
    _, ans := dfs(links, n, k, 0, 0)
    if aaa[0] != 1 {
        ans += 1
    }
    fmt.Println(ans)
}



Translate the above Go code to C++ and end with comment "
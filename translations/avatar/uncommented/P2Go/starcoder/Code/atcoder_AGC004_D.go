package main
import "fmt"
func dfs(links [][]int, n, k, v, p int) (int, int) {
    height_from_leaf := 0
    cut_count := 0
    for _, u := range links[v] {
        if u == 0 {
            continue
        }
        hgt, cut := dfs(links, n, k, u, v)
        height_from_leaf = max(height_from_leaf, hgt)
        cut_count += cut
    }
    height_from_leaf += 1
    if p!= 0 && height_from_leaf == k {
        height_from_leaf = 0
        cut_count += 1
    }
    return height_from_leaf, cut_count
}
func main() {
    var n, k int
    fmt.Scanf("%d %d", &n, &k)
    links := make([][]int, n)
    for i := range links {
        links[i] = make([]int, 0)
    }
    for i := 0; i < n-1; i++ {
        var a int
        fmt.Scanf("%d", &a)
        links[a-1] = append(links[a-1], i+1)
        links[i+1] = append(links[i+1], a)
    }
    _, ans := dfs(links, n, k, 0, 0)
    if links[0][0]!= 1 {
        ans += 1
    }
    fmt.Println(ans)
}

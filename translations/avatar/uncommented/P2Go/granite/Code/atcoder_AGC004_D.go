
package main

import (
    "bufio"
    "fmt"
    "os"
)

var (
    in  = bufio.NewReader(os.Stdin)
    out = bufio.NewWriter(os.Stdout)
)

func main() {
    var n, k int
    fmt.Fscanf(in, "%d%d", &n, &k)
    links := make([][]int, n)
    for i := 0; i < n; i++ {
        var a int
        fmt.Fscanf(in, "%d", &a)
        a--
        links[a] = append(links[a], i)
    }
    var ans int
    dfs(links, n, k, 0, 0, &ans)
    if links[0][0]!= 1 {
        ans++
    }
    fmt.Fprintln(out, ans)
    out.Flush()
}

func dfs(links [][]int, n, k, v, p, ans *int) (int, int) {
    heightFromLeaf := 0
    cutCount := 0
    for _, u := range links[v] {
        if u == 0 {
            continue
        }
        hgt, cut := dfs(links, n, k, u, v, ans)
        heightFromLeaf = max(heightFromLeaf, hgt)
        cutCount += cut
    }
    heightFromLeaf++
    if p!= 0 && heightFromLeaf == k {
        heightFromLeaf = 0
        cutCount++
    }
    return heightFromLeaf, cutCount
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}


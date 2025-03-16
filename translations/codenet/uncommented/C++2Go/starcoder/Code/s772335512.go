package main

import "fmt"

func main() {
    var N int
    fmt.Scanf("%d\n", &N)
    G := make([][]int, N)
    for i := 0; i < N; i++ {
        G[i] = make([]int, 0)
    }
    for i := 0; i < N-1; i++ {
        var x, y int
        fmt.Scanf("%d %d\n", &x, &y)
        x--
        y--
        G[x] = append(G[x], y)
        G[y] = append(G[y], x)
    }
    used := make([]bool, N)
    grundy := make([]int, N)
    dfs := func(v int) {
        used[v] = true
        grundy[v] = 0
        for i := 0; i < len(G[v]); i++ {
            if!used[G[v][i]] {
                dfs(G[v][i])
                grundy[v] ^= (grundy[G[v][i]] + 1)
            }
        }
    }
    dfs(0)
    if grundy[0]!= 0 {
        fmt.Println("Alice")
    } else {
        fmt.Println("Bob")
    }
}


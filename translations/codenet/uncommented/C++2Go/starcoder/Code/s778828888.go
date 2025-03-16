package main

import (
    "fmt"
    "sort"
)

func main() {
    var n, m, x int
    fmt.Scanf("%d %d %d", &n, &m, &x)

    a := make([]int, n+1)
    for i := 0; i < m; i++ {
        var temp int
        fmt.Scanf("%d", &temp)
        a[temp] = 1
    }

    ansl := 0
    ansr := 0
    for i := x; i <= n; i++ {
        ansr += a[i]
    }
    for i := x; i >= 0; i-- {
        ansl += a[i]
    }

    fmt.Printf("%d\n", min(ansl, ansr))
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}


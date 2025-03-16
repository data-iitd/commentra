package main

import "fmt"

func main() {
    var n, c int
    fmt.Scanf("%d %d\n", &n, &c)

    x := make([]int, n+1)
    v := make([]int, n+1)

    for i := 1; i < n+1; i++ {
        fmt.Scanf("%d %d\n", &x[i], &v[i])
    }

    lefttotal := make([]int, n+1)
    maxlefttotal := make([]int, n+1)
    for i := 1; i < n+1; i++ {
        lefttotal[i] = lefttotal[i-1] + v[i]
    }

    for i := 1; i < n+1; i++ {
        maxlefttotal[i] = max(maxlefttotal[i-1], lefttotal[i]-x[i])
    }

    righttotal := make([]int, n+1)
    maxrighttotal := make([]int, n+1)
    for i := 1; i < n+1; i++ {
        righttotal[i] = righttotal[i-1] + v[n-i+1]
    }

    for i := 1; i < n+1; i++ {
        maxrighttotal[i] = max(maxrighttotal[i-1], righttotal[i]-(c - x[n+1-i]))
    }

    ans := 0

    for i := 1; i < n+1; i++ {
        ans = max(ans, lefttotal[i]-x[i])
        ans = max(ans, lefttotal[i]-2*x[i]+maxrighttotal[n-i])
        ans = max(ans, righttotal[i]-(c -x[n+1-i]))
        ans = max(ans, righttotal[i]-2*(c-x[n+1-i])+maxlefttotal[n-i])
    }

    fmt.Println(ans)
}


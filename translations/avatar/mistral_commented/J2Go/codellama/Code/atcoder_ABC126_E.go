
package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    var n, m int
    var x, y, z int
    var cnt int
    var par []int
    var rank []int

    fmt.Scan(&n)
    fmt.Scan(&m)

    par = make([]int, n)
    rank = make([]int, n)

    for i := 0; i < n; i++ {
        par[i] = i
        rank[i] = 0
    }

    for i := 0; i < m; i++ {
        fmt.Scan(&x)
        fmt.Scan(&y)
        fmt.Scan(&z)
        x--
        y--
        if par[x] == x {
            par[x] = y
        } else {
            par[y] = x
        }
    }

    for i := 0; i < n; i++ {
        if par[i] == i {
            cnt++
        }
    }

    fmt.Println(cnt)
}


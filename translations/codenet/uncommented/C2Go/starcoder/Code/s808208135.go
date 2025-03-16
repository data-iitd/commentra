package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

const (
    N = 100000
    INF = 1000000
)

type Date struct {
    go, back, cost int
}

var n int
var d [N]int
var a [500000]Date

func root(b int) {
    var i, flag int

    for i = 0; i < n; i++ {
        d[i] = INF
    }
    d[0] = 0

    for flag = 1; flag!= 0; flag = 0 {
        for i = 0; i < b; i++ {
            if a[i].cost + d[a[i].back] < d[a[i].go] {
                d[a[i].go] = a[i].cost + d[a[i].back]
                flag = 1
            }
        }
    }
}

func main() {
    var i, j, k, u, count int
    var line string
    fmt.Scanf("%d", &n)
    for i = 0; i < n; i++ {
        fmt.Scanf("%d%d", &u, &k)
        for j = 0; j < k; j++ {
            fmt.Scanf("%d%d", &a[count].go, &a[count].cost)
            a[count].back = u
            count++
        }
    }
    root(count)
    for i = 0; i < n; i++ {
        fmt.Printf("%d %d\n", i, d[i])
    }
}


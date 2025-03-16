package main

import "fmt"

func main() {
    var n, k int
    var p [99999]int
    var i, j, l, m int
    var o int = 0

    fmt.Scanf("%d %d", &n, &k)

    for i = 0; i < n; i++ {
        fmt.Scanf("%d", &p[i])
    }

    for i = 0; i < n; i++ {
        l = i
        for j = i + 1; j < n; j++ {
            if p[j] < p[l] {
                l = j
            }
        }
        if l != i {
            m = p[i]
            p[i] = p[l]
            p[l] = m
        }
    }

    for i = 0; i < k; i++ {
        o += p[i]
    }

    fmt.Println(o)
}


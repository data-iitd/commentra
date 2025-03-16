package main

import "fmt"

func main() {
    var n, m int
    fmt.Scan(&n, &m)
    round_complexity := make([]int, n)
    george_complexity := make([]int, m)
    for i := 0; i < n; i++ {
        fmt.Scan(&round_complexity[i])
    }
    for i := 0; i < m; i++ {
        fmt.Scan(&george_complexity[i])
    }
    i, j := 0, 0
    for i < n && j < m {
        if round_complexity[i] <= george_complexity[j] {
            i++
        }
        j++
    }
    fmt.Println(n - i)
}


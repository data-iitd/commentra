
package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n, m int
    fmt.Scanf("%d %d", &n, &m)
    if n < 1 {
        if m < 1 {
            fmt.Println(n, m)
            os.Exit(0)
        }
        fmt.Println("Impossible")
        os.Exit(0)
    }
    if m > n {
        min := m
        max := n + m - 1
        fmt.Println(min, max)
    }
    if m <= n {
        min := n
        max := n + m - 1
        if m == 0 {
            max = n
        }
        fmt.Println(min, max)
    }
}


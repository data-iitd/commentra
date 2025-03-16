package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var n int
    fmt.Scanf("%d", &n)

    a := make([]int, n)
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }
    curr := 0
    for i := 0; i < n; i++ {
        if a[i] == curr+1 {
            curr++
        }
    }
    if curr > 0 {
        fmt.Printf("%d\n", n-curr)
    } else {
        fmt.Printf("-1\n")
    }
}


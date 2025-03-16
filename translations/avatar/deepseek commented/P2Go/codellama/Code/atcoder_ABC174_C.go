package main

import (
    "fmt"
    "math"
    "strconv"
    "strings"
)

func main() {
    var k int
    fmt.Scan(&k)
    t := 0
    for i := 1; i <= k; i++ {
        t = (t % k) * 10 + 7
        if t % k == 0 {
            fmt.Println(i)
            break
        }
    }
    if i > k {
        fmt.Println(-1)
    }
}


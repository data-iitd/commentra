package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    var a, b int
    var ans int

    fmt.Scanf("%d %d", &a, &b)

    ans = 0
    if a >= 13 {
        ans = b
    } else if a >= 6 {
        ans = b / 2
    }

    fmt.Printf("%d\n", ans)
}


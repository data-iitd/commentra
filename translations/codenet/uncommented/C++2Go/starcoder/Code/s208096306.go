package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scanf("%d\n", &n)

    var ans int
    fmt.Scanf("%d\n", &ans)

    for i := 1; i < n; i++ {
        var a int
        fmt.Scanf("%d\n", &a)
        ans = int(math.GCD(float64(ans), float64(a)))
    }

    fmt.Printf("%d\n", ans)
}


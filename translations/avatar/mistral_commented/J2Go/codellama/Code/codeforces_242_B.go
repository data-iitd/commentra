
package main

import (
    "fmt"
    "math"
)

func main() {
    var n int
    fmt.Scan(&n)

    a := make([]int, n)
    b := make([]int, n)

    var left, right int = math.MaxInt32, 0

    for i := 0; i < n; i++ {
        fmt.Scan(&a[i])
        fmt.Scan(&b[i])
        left = int(math.Min(float64(left), float64(a[i])))
        right = int(math.Max(float64(right), float64(b[i])))
    }

    for i := 0; i < n; i++ {
        if left == a[i] && right == b[i] {
            fmt.Println(i + 1)
            return
        }
    }

    fmt.Println(-1)
}


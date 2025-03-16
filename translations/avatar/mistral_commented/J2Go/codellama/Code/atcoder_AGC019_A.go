package main

import (
    "fmt"
    "math"
)

func main() {
    var Q, H, S, D, N int64
    fmt.Scan(&Q, &H, &S, &D, &N)

    onePrice := int64(math.Min(math.Min(float64(Q*4), float64(H*2)), float64(S)))

    if onePrice <= D/2 {
        fmt.Println(N * onePrice)
    } else {
        fmt.Println((N/2)*D + (N%2)*onePrice)
    }
}


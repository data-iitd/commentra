package main

import (
    "fmt"
    "math"
)

func main() {
    var N, K int
    fmt.Scanf("%d %d\n", &N, &K)

    v := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &v[i])
    }

    // ceil((N-1) / (K-1))
    count := int(math.Ceil((float64(N-1)) / (float64(K-1))))
    fmt.Printf("%d\n", count)
}


package main

import (
    "fmt"
    "math"
)

func main() {
    var N int
    fmt.Scanf("%d\n", &N)
    A := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &A[i])
    }

    m := A[0]
    M := A[0]
    for i := 0; i < N; i++ {
        if A[i] < m {
            m = A[i]
        }
        if A[i] > M {
            M = A[i]
        }
    }

    fmt.Printf("%d\n", M-m)
}


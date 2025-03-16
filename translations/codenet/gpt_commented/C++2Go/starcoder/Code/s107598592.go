package main

import (
    "fmt"
    "sort"
)

func main() {
    // Read the number of elements
    var N int
    fmt.Scanf("%d\n", &N)

    // Initialize two vectors to store the input values
    X := make([]int, N)
    Y := make([]int, N)

    // Read input values into vector X and copy them to vector Y
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &X[i])
        Y[i] = X[i]
    }

    // Sort vector Y to find the median
    sort.Ints(Y)

    // Find the median value (middle element for odd N, or lower middle for even N)
    y := Y[N/2]

    // Output the appropriate median value for each element in X
    for i := 0; i < N; i++ {
        // If the current element in X is less than the median
        if X[i] < Y[N/2] {
            fmt.Printf("%d\n", Y[N/2]) // Output the upper median
        } else {
            fmt.Printf("%d\n", Y[N/2 - 1]) // Output the lower median
        }
    }
}


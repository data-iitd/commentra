package main

import (
    "fmt"
    "math"
)

func main() {
    // Declare variables N and K to hold the number of elements and the divisor respectively
    var N, K int

    // Read the values of N and K from standard input
    fmt.Scanf("%d %d\n", &N, &K)

    // Initialize a vector of size N to store the input elements
    v := make([]int, N)

    // Read N integers from standard input and store them in the vector v
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &v[i])
    }

    // Calculate the number of groups needed based on the formula ceil((N-1) / (K-1))
    // This is done using integer arithmetic to avoid floating-point operations
    count := int(math.Ceil((float64(N-1)) / (float64(K-1))))

    // Output the calculated count of groups
    fmt.Printf("%d\n", count)
}


package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables for the number of elements (N) and the threshold value (X)
    var N, X int

    // Read the values of N and X from standard input
    fmt.Scanf("%d %d\n", &N, &X)

    // Initialize a vector L of size N to store the elements
    L := make([]int, N)

    // Read N elements into the vector L
    for i := 0; i < N; i++ {
        fmt.Scanf("%d\n", &L[i])
    }

    // Initialize index variable and a variable to accumulate the sum
    var i int
    d := 0

    // Iterate through the elements of the vector L
    for i = 0; i < N; i++ {
        // Accumulate the sum of elements
        d = d + L[i]

        // Check if the accumulated sum exceeds the threshold X
        if d > X {
            break
        }
    }

    // Output the number of elements processed before exceeding X
    fmt.Printf("%d\n", i+1) // i + 1 because we want to count the number of elements
}


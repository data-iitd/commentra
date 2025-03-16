package main

import (
    "fmt"
)

func main() {
    // Declare two integer variables n and m
    var n, m int

    // Read two integers from standard input
    // n represents the number of rows, and m represents the number of columns
    fmt.Scanf("%d %d", &n, &m)

    // Calculate the product of (n - 1) and (m - 1)
    // This represents the number of internal edges in a grid of n by m cells
    fmt.Println((n - 1) * (m - 1))

    // No need to flush the output buffer in Go, as it is handled automatically
}

// <END-OF-CODE>

package main

import (
    "fmt"
    "os"
)

func main() {
    // Declare two integer variables n and m
    var n, m int

    // Read two integers from standard input
    // n represents the number of rows, and m represents the number of columns
    fmt.Scanf("%d %d", &n, &m)

    // Calculate the product of (n - 1) and (m - 1)
    // This represents the number of internal edges in a grid of n by m cells
    fmt.Printf("%d\n", (n - 1) * (m - 1))

    // Flush the output buffer to ensure all output is printed
    os.Stdout.Sync()
}


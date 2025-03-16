package main

import (
    "fmt"
    "math"
)

func main() {
    // Declare variables
    var n, a, b, i, j uint64

    // Read an unsigned long long integer from user input
    fmt.Scanf("%d", &n)

    // Calculate the number of ways to choose 2 items from n items
    // This is done using the formula: b = n * (n - 1) / 2
    b = uint64(math.Floor(float64(n * (n - 1)) / 2))

    // Print the result
    fmt.Printf("%d\n", b)
}


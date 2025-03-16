package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare two int variables to hold the input values
    var a, b int

    // Read two integers from the standard input
    fmt.Scanf("%d %d\n", &a, &b)

    // Check if the sum of a and b is even
    if (a + b) % 2 == 0 {
        // If the sum is even, calculate and output the average
        fmt.Printf("%d\n", (a + b) / 2)
    } else {
        // If the sum is odd, output "IMPOSSIBLE"
        fmt.Printf("IMPOSSIBLE\n")
    }
}


package main

import (
    "fmt"
)

func main() {
    // Declare two variables to hold the input values
    var a, b int64

    // Read two integers from the standard input
    fmt.Scan(&a, &b)

    // Check if the sum of a and b is even
    if (a+b)%2 == 0 {
        // If the sum is even, calculate and output the average
        fmt.Println((a + b) / 2)
    } else {
        // If the sum is odd, output "IMPOSSIBLE"
        fmt.Println("IMPOSSIBLE")
    }
}

// <END-OF-CODE>

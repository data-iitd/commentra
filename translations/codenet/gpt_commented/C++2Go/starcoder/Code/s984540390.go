package main

import (
    "fmt"
    "math"
)

// Initialize variables to store the answer, maximum value, sum, minimum value, and count
var ans, mx, sum, mn = 1e8, cnt = 1

func main() {
    // Read the input value for h
    var h int
    fmt.Scanf("%d", &h)

    // Loop until h becomes 1
    for h!= 1 {
        // If h is odd, decrement it by 1 to make it even
        if h%2!= 0 {
            h--
        }

        // Divide h by 2
        h /= 2

        // Double the count for each iteration
        cnt *= 2

        // Accumulate the count into the answer
        ans += cnt
    }

    // Output the final answer incremented by 1
    fmt.Printf("%d\n", ans+1)
}


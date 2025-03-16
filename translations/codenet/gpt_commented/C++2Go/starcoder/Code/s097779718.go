package main

import (
    "fmt"
    "math"
)

// Function to compute the Greatest Common Divisor (GCD) using Euclid's algorithm
func Euclid(x, y int64) int64 {
    var tmp int64

    // Ensure x is the larger number
    if x < y {
        tmp = x
        x = y
        y = tmp
    }

    // If y divides x evenly, y is the GCD
    if x%y == 0 {
        return y
    }

    // Recursively call Euclid with y and the remainder of x divided by y
    return Euclid(y, x%y)
}

func main() {
    var A, B int64 // Declare variables to hold the two input numbers
    fmt.Scan(&A, &B)  // Read input values for A and B

    // Calculate and output the Least Common Multiple (LCM) using the formula LCM(A, B) = (A * B) / GCD(A, B)
    fmt.Println(A * B / Euclid(A, B))
}


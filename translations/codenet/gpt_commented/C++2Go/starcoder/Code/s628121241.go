package main

import (
    "fmt"
    "math"
)

// Function to compute the greatest common divisor (GCD) of two integers
func gcd(a, b int) int {
    // Base case: if 'a' is 0, return 'b' as the GCD
    if a == 0 {
        return b
    }
    // Recursive case: call gcd with 'b' modulo 'a' and 'a'
    return gcd(b%a, a)
}

func main() {
    var R int
    fmt.Scanf("%d", &R)
    if R < 1200 {
        fmt.Println("ABC")
    } else if R >= 2800 {
        fmt.Println("AGC")
    } else {
        fmt.Println("ARC")
    }
}


<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
)

// Function to calculate the greatest common divisor (GCD) using recursion
func gcd(a, b int) int {
    if a == 0 {
        return b
    }
    return gcd(b%a, a)
}

func main() {
    // Take an integer input from the user
    var R int
    fmt.Scanf("%d", &R)

    // Check the value of R and print the corresponding output
    if R < 1200 {
        fmt.Println("ABC")
    } else if R >= 2800 {
        fmt.Println("AGC")
    } else {
        fmt.Println("ARC")
    }
}


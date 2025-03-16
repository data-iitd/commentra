<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
    "fmt"
    "math"
    "strings"
    "strconv"
)

// Define an array to keep track of unavailable digits
var d [10]bool

// Define variables to store the number and the number of unavailable digits
var n, k int

// Define a boolean variable to check if the current number is valid
var hantei bool

func main() {
    // Read the initial number and the number of unavailable digits
    fmt.Scanf("%d %d\n", &n, &k)

    // Mark the unavailable digits
    for i := 0; i < k; i++ {
        var a int
        fmt.Scanf("%d\n", &a)
        d[a] = true
    }

    // Loop until a valid number is found
    for {
        // Copy the current number to a temporary variable and initialize the check flag
        x := n
        hantei = true

        // Check each digit of the number
        for x > 0 {
            // If a digit is unavailable, set the check flag to false and break the loop
            if d[x%10] {
                hantei = false
                break
            }
            // Move to the next digit
            x /= 10
        }

        // If the number is valid, print it and break the loop
        if hantei {
            fmt.Printf("%d\n", n)
            break
        }

        // Increment the number and check again
        n++
    }
}


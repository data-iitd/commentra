package main

import (
    "fmt"
    "math"
    "os"
    "strconv"
    "strings"
)

// Define a pair type for convenience
type P struct {
    x, y int
}

// Array to track forbidden digits
var d [10]bool

func main() {
    // Read the initial number 'n' and the count of forbidden digits 'k'
    n, k := read()

    // Read the forbidden digits and mark them in the array
    for i := 0; i < k; i++ {
        a := read()
        d[a] = true
    }

    // Infinite loop to find the next valid number
    for {
        x := n // Start checking from the current number 'n'
        hantei := true // Reset the validity flag for the new number

        // Check each digit of the number 'x'
        for x > 0 {
            // If the current digit is forbidden
            if d[x%10] {
                hantei = false // Mark the number as invalid
                break // Exit the digit checking loop
            }
            x /= 10 // Remove the last digit
        }

        // If the number is valid (no forbidden digits found)
        if hantei {
            fmt.Println(n) // Output the valid number
            break // Exit the infinite loop
        }
        n++ // Increment the number and check the next one
    }
}

// Read a single integer value from stdin.
func read() int {
    var n int
    fmt.Scan(&n)
    return n
}

// END-OF-CODE

'''

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Define constants for base and maximum size
const B = 13131
const N = 500000 + 7

// Declare global variables
var n int
var s [N]byte
var f [N]uint64
var g [N]int
var map [N]uint64
var cnt uint64

// Function to compute power of a number with a given exponent
func pow(a uint64, k int) uint64 {
    // Adjust exponent if negative
    if k < 0 {
        k += (1 << 63) - 1
    }
    t := uint64(1) // Initialize result
    // Exponentiation by squaring
    for ; k > 0; a, k = a*a, k>>1 {
        if k&1 == 1 {
            t = t * a
        }
    }
    return t
}

func main() {
    // Read input values: number of operations and the operations string
    fmt.Scanf("%d%s", &n, string(s[1:]))

    // Process each character in the input string
    for i := 1; i <= n; i++ {
        // If the character is '+' or '-', update f and g arrays
        if s[i] == '+' || s[i] == '-' {
            f[i] = f[i-1] + (s[i] == '+'? 1 : -1) * pow(B, g[i] = g[i-1])
        } else {
            // If the character is '<' or '>', update f and g arrays accordingly
            f[i] = f[i-1] // No change in f
            g[i] = g[i-1] + (s[i] == '<'? -1 : 1) // Update g based on direction
        }
    }

    // Iterate backwards through the string to count valid combinations
    for i := n; i > 0; i-- {
        map[f[i]]++ // Increment the count of the current f value
        // Update the counter with the number of valid combinations found
        cnt += map[f[n]*pow(B, g[i-1])+f[i-1]]
    }

    // Output the final count of valid combinations
    fmt.Printf("%d\n", cnt)
}


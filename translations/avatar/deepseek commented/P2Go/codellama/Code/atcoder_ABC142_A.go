
package main

import (
    "fmt"
    "math"
    "strconv"
    "strings"
)

func nextInt() int {
    var n int
    fmt.Scan(&n)
    return n
}

func nextInts() []int {
    var n int
    fmt.Scan(&n)
    var a []int
    for i := 0; i < n; i++ {
        var x int
        fmt.Scan(&x)
        a = append(a, x)
    }
    return a
}

func main() {
    // Read the value of n from input
    n := nextInt()

    // Initialize a counter to keep track of odd numbers
    t := 0

    // Loop through each number from 0 to n-1
    for i := 0; i < n; i++ {
        // Check if the current index plus one is odd
        if i+1&1 == 1 {
            // Increment the counter if the condition is true
            t++
        }
    }

    // Calculate the ratio of odd numbers to the total numbers and print it
    fmt.Println(float64(t) / float64(n))
}


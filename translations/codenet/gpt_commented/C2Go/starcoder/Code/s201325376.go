package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold the range (a, b) and the number (c)
    var a, b, c, i, count int

    // Read three integers from user input: a, b, and c
    fmt.Scanf("%d%d%d", &a, &b, &c)

    // Initialize count to zero to keep track of how many numbers in the range divide c
    count = 0

    // Loop through each integer i from a to b (inclusive)
    for i = a; i <= b; i++ {
        // Check if c is divisible by i
        if c%i == 0 {
            // If divisible, increment the count
            count++
        }
    }

    // Print the total count of numbers that divide c
    fmt.Printf("%d\n", count)
}


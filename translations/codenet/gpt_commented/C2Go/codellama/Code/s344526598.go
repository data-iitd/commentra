package main

import "fmt"

func main() {
    // Declare variables
    var i, j, x [10000]int

    // Initialize the array x with zeros
    for i = 0; i < 10000; i++ {
        x[i] = 0
    }

    // Read the first input value into the array
    i = 0
    fmt.Scan(&x[i])

    // Continue reading input values until a zero is encountered
    for i = 0; x[i] != 0; i++ {
        fmt.Scan(&x[i])
    }

    // Print the case number and the corresponding value from the array
    for j = 0; j < i; j++ {
        fmt.Printf("Case %d: %d\n", j+1, x[j])
    }
}


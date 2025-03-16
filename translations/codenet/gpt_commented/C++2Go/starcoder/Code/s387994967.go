package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare two integer variables A and B
    var A, B int

    // Read input values for A and B from the user
    fmt.Scanf("%d %d", &A, &B)

    // Check if A is between 6 (inclusive) and 13 (exclusive)
    if A >= 6 && A < 13 {
        // If true, output half of B
        fmt.Println(B / 2)
    }

    // Check if A is less than 6
    if A < 6 {
        // If true, output 0
        fmt.Println(0)
    }

    // Check if A is greater than or equal to 13
    if A >= 13 {
        // If true, output the value of B
        fmt.Println(B)
    }
}


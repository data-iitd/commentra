package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold input values and the result
    var a, b int

    // Read two integers from standard input
    fmt.Scanf("%d %d", &a, &b)

    // Initialize the answer variable to zero
    var ans int = 0

    // Determine the value of ans based on the value of a
    if a >= 13 {
        // If a is 13 or greater, set ans to b
        ans = b
    } else if a >= 6 {
        // If a is between 6 and 12, set ans to half of b
        ans = b / 2
    }

    // Output the result
    fmt.Printf("%d\n", ans)
}


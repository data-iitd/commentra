package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Global variable to control debug output
var debug bool

func main() {
    // Declare variables for input
    var n, k, x, y int

    // Read input values: n (total items), k (threshold), x (cost for first k items), y (cost for items beyond k)
    n, k, x, y = readInput()

    // Initialize sum to accumulate total cost
    sum := 0

    // Loop through each item from 1 to n
    for i := 1; i <= n; i++ {
        // If the current item index exceeds k, add cost y; otherwise, add cost x
        if i > k {
            sum += y
        } else {
            sum += x
        }
    }

    // Output the total calculated cost
    fmt.Println(sum)
}

// Read input from stdin
func readInput() (int, int, int, int) {
    var n, k, x, y int

    fmt.Scanf("%d %d %d %d", &n, &k, &x, &y)

    return n, k, x, y
}

// 
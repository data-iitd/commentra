

package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)  // Taking an integer input from the user
    i, j := 1, n*n   // Initializing variables i and j

    // Starting a for loop that iterates from 1 to n*n
    for i < j {
        fmt.Println(i, j)  // Printing the current values of i and j
        i++                // Incrementing i by 1
        j--                // Decrementing j by 1
    }
}



package main

import "fmt"

func main() {
    // Read an integer input from the user
    var n int
    fmt.Scan(&n)

    // Initialize two variables: 'i' starting from 1 and 'j' starting from n*n
    i, j := 1, n*n

    // Loop until 'i' is less than 'j'
    for i < j {
        // Print the current values of 'i' and 'j'
        fmt.Printf("%d %d\n", i, j)

        // Increment 'i' to move towards the center
        i++

        // Decrement 'j' to move towards the center
        j--
    }
}

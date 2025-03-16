package main

import (
    "fmt"
)

func main() {
    // Declare variables for the number of elements (n), the threshold (k), and a counter (cnt)
    var n, k, cnt int

    // Read the number of elements and the threshold value from user input
    fmt.Scan(&n, &k)

    // Initialize the counter to zero
    cnt = 0

    // Loop through each element, decrementing n until it reaches zero
    for n > 0 {
        var h int

        // Read the current element from user input
        fmt.Scan(&h)

        // Check if the current element is greater than or equal to the threshold
        if h >= k {
            // Increment the counter if the condition is met
            cnt++
        }
        n-- // Decrement n
    }

    // Output the final count of elements that met or exceeded the threshold
    fmt.Println(cnt)
}

// <END-OF-CODE>

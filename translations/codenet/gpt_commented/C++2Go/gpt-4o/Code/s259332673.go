package main

import (
    "fmt"
)

func main() {
    // Declare variables to hold the input values
    var h1, h2, m1, m2, k int

    // Read input values: start time (h1:m1), end time (h2:m2), and a duration k
    fmt.Scan(&h1, &m1, &h2, &m2, &k)

    // Calculate the total minutes from the start time to the end time
    ans := (h2 * 60 + m2) - (h1 * 60 + m1)

    // Output the result after subtracting the duration k from the total minutes
    fmt.Println(ans - k)
}

// <END-OF-CODE>

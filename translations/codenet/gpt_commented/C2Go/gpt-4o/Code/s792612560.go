package main

import (
    "fmt"
)

func main() {
    // Declare an integer variable 'n' for input and a variable 'm' for storing the result
    var n int
    var m uint64

    // Read an integer value from the user and store it in 'n'
    fmt.Scan(&n)

    // Initialize 'm' with the value of 'n'
    m = uint64(n)

    // Decrease 'n' by 1 to prepare for the factorial calculation
    n--

    // Loop to calculate the factorial of 'n' (m = n!)
    for n > 1 {
        // Multiply 'm' by the current value of 'n'
        m *= uint64(n)
        n--
    }

    // Print the calculated factorial value stored in 'm'
    fmt.Println(m)
}

// <END-OF-CODE>

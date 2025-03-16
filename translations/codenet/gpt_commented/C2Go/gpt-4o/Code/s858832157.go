package main

import (
    "fmt"
)

func main() {
    // Initialize a counter variable 'i' to track the case number
    i := 1
    var input int

    // Start an infinite loop to continuously accept user input
    for {
        // Read an integer input from the user
        fmt.Scan(&input)

        // Check if the input is zero, which indicates the end of input
        if input == 0 {
            // Exit the loop if the input is zero
            break
        }

        // Print the case number and the input value
        fmt.Printf("Case %d: %d\n", i, input)

        // Increment the case number for the next iteration
        i++
    }
}

// <END-OF-CODE>

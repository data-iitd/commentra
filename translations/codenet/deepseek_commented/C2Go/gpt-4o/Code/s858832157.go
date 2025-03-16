package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    i := 1 // Declare and initialize the case number variable

    // Start an infinite loop
    for {
        var input int // Declare a variable to hold user input
        fmt.Scan(&input) // Read an integer from the user

        if input == 0 { // Check if the input is 0
            break // Exit the loop if the input is 0
        }

        fmt.Printf("Case %d: %d\n", i, input) // Print the current case number and input value
        i++ // Increment the case number
    }
}

package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var sum int64 = 0 // Declare and initialize the sum variable
    var m, n, min, max int // Declare variables for the current input, number of inputs, min, and max

    fmt.Scanf("%d\n", &n) // Read the number of inputs

    // Loop through each input
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &m) // Read the current input
        sum += int64(m) // Update the sum with the current input

        // Check if it's the first input to set initial min and max values
        if i == 0 {
            min = m
            max = m
        }

        // Update the min value if the current input is smaller
        if min > m {
            min = m
        }

        // Update the max value if the current input is larger
        if max < m {
            max = m
        }
    }

    // Output the minimum, maximum, and sum of the inputs
    fmt.Printf("%d %d %d\n", min, max, sum)
}

// <END-OF-CODE>

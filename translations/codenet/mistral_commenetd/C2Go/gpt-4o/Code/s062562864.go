package main
// Include the main package

import (
    "fmt"
    // Import the fmt package for formatted I/O
)

func main() {
    // Declare the main function

    var a, b, c, d int
    // Declare variables a, b, c, and d

    fmt.Scanf("%d %d %d %d", &a, &b, &c, &d)
    // Read four integers from the standard input and store them in variables a, b, c, and d

    i := a * b
    // Multiply variables a and b and store the result in variable i

    j := c * d
    // Multiply variables c and d and store the result in variable j

    if i > j {
        // Check if the value of i is greater than j

        fmt.Println(i)
        // If true, print the value of i

    } else {
        // If the condition in the if statement is false

        fmt.Println(j)
        // Print the value of j
    }
}

// End the main function

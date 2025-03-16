package main
// Import the main package

import (
    "fmt"
    // Import the fmt package for formatted I/O
)

func main() {
    var a, b, c int
    // Declare three integer variables: a, b, and c

    fmt.Scanf("%d%d%d", &a, &b, &c)
    // Use the Scanf function to read three integers from the standard input
    // and assign them to the variables a, b, and c respectively

    if a < b && b < c {
        fmt.Println("Yes")
        // If the condition a < b && b < c is true, print the string "Yes"
        // followed by a newline character to the standard output
    } else {
        fmt.Println("No")
        // If the condition a < b && b < c is false, print the string "No"
        // followed by a newline character to the standard output
    }
}

// End of the main function
// The program has run successfully

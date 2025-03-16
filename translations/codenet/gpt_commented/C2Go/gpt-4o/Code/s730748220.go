package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var n int // Declare an integer variable n

    // Read an integer input from the user
    fmt.Scan(&n)

    // Calculate and print the result based on the input n
    // The expression (24 + (24 - n)) simplifies to (48 - n)
    fmt.Println(24 + (24 - n))
}

// <END-OF-CODE>

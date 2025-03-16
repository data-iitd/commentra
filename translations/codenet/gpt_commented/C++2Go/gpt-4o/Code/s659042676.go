package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var a, b int // Declare two integer variables to store input values

    // Read two integer values from standard input
    fmt.Scan(&a, &b)

    // Calculate and output the result of the expression (6 - a - b)
    // This assumes that a and b are part of a game or problem where their sum should not exceed 6
    fmt.Println(6 - a - b)
}

// <END-OF-CODE>

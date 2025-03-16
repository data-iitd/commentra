package main

import (
    "fmt" // Import the fmt package for input and output operations
)

func main() {
    var x1, y1, x2, y2 int64 // Declare four int64 variables for the coordinates
    fmt.Scan(&x1, &y1, &x2, &y2) // Read four int64 integers from the standard input

    // Calculate the differences between the coordinates
    dx := x2 - x1
    dy := y2 - y1

    // Compute the new coordinates based on the differences
    x3 := x2 - dy
    y3 := y2 + dx
    x4 := x1 - dy
    y4 := y1 + dx

    // Output the new coordinates
    fmt.Println(x3, y3, x4, y4)
}

// <END-OF-CODE>

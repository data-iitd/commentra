package main

import (
    "fmt"
)

func main() {
    // Declare variables to hold the dimensions and results
    var a, b, x, y int

    // Read two integer inputs from the user (representing dimensions)
    fmt.Scanf("%d%d", &a, &b)

    // Calculate the perimeter of the rectangle (2 * (length + width))
    x = 2*a + 2*b

    // Calculate the area of the rectangle (length * width)
    y = a * b

    // Output the area and perimeter
    fmt.Printf("%d %d\n", y, x)

    // Return 0 to indicate successful execution (not needed in Go)
}

// <END-OF-CODE>

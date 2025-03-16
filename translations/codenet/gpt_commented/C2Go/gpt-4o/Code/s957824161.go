package main

import (
    "fmt"
)

func main() {
    // Declare variables for storing two integers
    var x, y int

    // Read two integers from user input
    fmt.Scanf("%d %d", &x, &y)

    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    fmt.Printf("%d %d\n", x*y, 2*x+2*y)
}

// <END-OF-CODE>

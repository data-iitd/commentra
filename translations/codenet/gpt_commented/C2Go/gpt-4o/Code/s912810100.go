package main

import (
    "fmt"
)

func main() {
    // Declare variables to hold two integers and the results
    var a, b, x, y int

    // Read two integers from user input
    fmt.Scanf("%d%d", &a, &b)

    // Calculate the product of a and b
    x = a * b

    // Calculate the perimeter of a rectangle with sides a and b
    y = (a + b) * 2

    // Print the results: product and perimeter
    fmt.Printf("%d %d\n", x, y)
}

// <END-OF-CODE>

package main

import "fmt"

func main() {
    // Declare two integer variables to hold the input values
    var a, b int

    // Read two integers from the user input
    fmt.Scanf("%d %d", &a, &b)

    // Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
    fmt.Printf("%d %d\n", a * b, 2 * (a + b))
}


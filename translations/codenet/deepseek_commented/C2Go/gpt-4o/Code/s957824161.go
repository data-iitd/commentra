package main // Define the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
    var x, y int // Declare two integer variables to store user input
    fmt.Scanf("%d %d", &x, &y) // Read two integers from standard input and store them in x and y
    fmt.Printf("%d %d\n", x*y, 2*x+2*y) // Print the product of x and y and the perimeter of the rectangle
}

// <END-OF-CODE>

package main

import "fmt"

// Declare global variables for storing two integers
var x, y int

func main() {
    // Read two integers from user input
    fmt.Scanf("%d %d", &x, &y)
    
    // Calculate the product of x and y, and the perimeter of a rectangle with sides x and y
    // Print the results: product and perimeter
    fmt.Printf("%d %d\n", x * y, 2 * x + 2 * y)
    
    // Return 0 to indicate successful completion of the program
    return 0
}


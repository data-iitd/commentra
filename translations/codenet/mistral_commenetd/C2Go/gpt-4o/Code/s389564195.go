package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Declare the main function
    var x, kotae int // Declare two integer variables, x and kotae

    // Ask the user to input an integer value for x
    fmt.Print("Enter an integer value for x: ")
    fmt.Scan(&x) // Read the input value into x

    // Calculate the cube of the input integer x and store the result in the variable kotae
    kotae = x * x * x

    // Print the result (the cube of the input integer) to the console
    fmt.Printf("The cube of %d is %d.\n", x, kotae)

    // No explicit return needed in Go
}

// <END-OF-CODE>

package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Main function where program execution begins
    var x int // Declare an integer variable x

    // Prompt the user for input and read an integer value into x
    fmt.Scanf("%d", &x)

    // Calculate the cube of x and print the result
    fmt.Println(x * x * x)

    // Return statement is not needed in Go's main function
}

// <END-OF-CODE>

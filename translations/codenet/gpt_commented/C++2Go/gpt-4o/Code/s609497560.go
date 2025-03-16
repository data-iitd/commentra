package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Main function where the execution of the program begins
    var a int // Declare an integer variable 'a' to store user input

    // Prompt the user to enter a value for 'a'
    fmt.Print("Enter a number: ") 
    fmt.Scan(&a) // Read the input value from the user and store it in 'a'

    // Calculate the expression a + a^2 + a^3 and output the result
    result := a + (a * a) + (a * a * a)
    fmt.Println(result) // Output the result

    // Return is not needed in Go's main function
}

// <END-OF-CODE>

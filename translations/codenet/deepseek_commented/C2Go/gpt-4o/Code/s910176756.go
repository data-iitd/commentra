package main // Define the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function, the entry point of the program
    var a, b, c int // Declare three integer variables to store the operands and the result
    var op rune // Declare a rune variable to store the operator

    for { // Start an infinite loop
        _, err := fmt.Scanf("%d %c %d", &a, &op, &b) // Read two integers and an operator from the user
        if err != nil { // Check for input errors
            break // Exit the loop if there's an error
        }

        switch op { // Use a switch statement to handle different operators
        case '+': // Check if the operator is addition
            c = a + b // Perform the addition operation
            fmt.Println(c) // Print the result
        case '-': // Check if the operator is subtraction
            c = a - b // Perform the subtraction operation
            fmt.Println(c) // Print the result
        case '*': // Check if the operator is multiplication
            c = a * b // Perform the multiplication operation
            fmt.Println(c) // Print the result
        case '/': // Check if the operator is division
            if b != 0 { // Check for division by zero
                c = a / b // Perform the division operation
                fmt.Println(c) // Print the result
            } else {
                fmt.Println("Error: Division by zero") // Print an error message for division by zero
            }
        default: // If the operator is not recognized
            return // Exit the program
        }
    }
}

// <END-OF-CODE>

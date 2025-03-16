package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Start of the main function
    var a, b, c int // Declare three integer variables: a, b, and c
    var op rune // Declare a rune variable: op

    fmt.Scanf("%d %c %d", &a, &op, &b) // Read an integer, an operator, and another integer from the standard input

    for { // Start of an infinite loop
        if op == '+' { // Check if the operator is '+'
            c = a + b // If so, add the two numbers and store the result in variable c
            fmt.Println(c) // Print the result to the standard output
        } else if op == '-' { // Check if the operator is '-'
            c = a - b // If so, subtract the second number from the first and store the result in variable c
            fmt.Println(c) // Print the result to the standard output
        } else if op == '*' { // Check if the operator is '*'
            c = a * b // If so, multiply the two numbers and store the result in variable c
            fmt.Println(c) // Print the result to the standard output
        } else if op == '/' { // Check if the operator is '/'
            c = a / b // If so, divide the first number by the second and store the result in variable c
            fmt.Println(c) // Print the result to the standard output
        } else { // If the operator is not one of the above, break the loop
            break
        }

        fmt.Scanf("%d %c %d", &a, &op, &b) // Read the next set of numbers and operator from the standard input
    }
}

// <END-OF-CODE>

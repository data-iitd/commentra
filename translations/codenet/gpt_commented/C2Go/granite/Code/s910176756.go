
package main

import "fmt"

func main() {
    // Declare variables for two integers and one character operator
    var a, b int
    var op byte

    // Read input values: two integers and an operator
    fmt.Scan(&a, &op, &b)

    // Start an infinite loop to continuously process operations
    for {
        // Check if the operator is addition
        if op == '+' {
            c := a + b // Perform addition
            fmt.Println(c) // Output the result
        } 
        // Check if the operator is subtraction
        else if op == '-' {
            c := a - b // Perform subtraction
            fmt.Println(c) // Output the result
        } 
        // Check if the operator is multiplication
        else if op == '*' {
            c := a * b // Perform multiplication
            fmt.Println(c) // Output the result
        } 
        // Check if the operator is division
        else if op == '/' {
            c := a / b // Perform division
            fmt.Println(c) // Output the result
        } 
        // If the operator is not recognized, exit the loop
        else {
            break // Exit the loop if an invalid operator is provided
        }

        // Read the next set of inputs: two integers and an operator
        fmt.Scan(&a, &op, &b)
    }

    // 
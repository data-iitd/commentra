
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Global variables
var top int
var S []int // Stack to hold integers

// Function to push an integer onto the stack
func push(x int) {
    S = append(S, x) // Append the value to the stack
    top++ // Increment top
}

// Function to pop an integer from the stack
func pop() int {
    top-- // Decrement top
    return S[top] // Return the top value
}

func main() {
    var a, b int // Variables to hold the operands for operations
    var s string // Variable to hold the input string
    var err error // Variable to hold any errors encountered during input

    // Initialize the stack
    S = make([]int, 0)
    top = 0

    // Read input until EOF
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        s = scanner.Text() // Read the input string

        // Check for addition operation
        if s[0] == '+' {
            b = pop() // Pop the top two values from the stack
            a = pop()
            push(a + b) // Push the result of addition back onto the stack
        }
        // Check for subtraction operation
        else if s[0] == '-' {
            b = pop() // Pop the top two values from the stack
            a = pop()
            push(a - b) // Push the result of subtraction back onto the stack
        }
        // Check for multiplication operation
        else if s[0] == '*' {
            b = pop() // Pop the top two values from the stack
            a = pop()
            push(a * b) // Push the result of multiplication back onto the stack
        }
        // If the input is a number, convert it and push onto the stack
        else {
            a, err = strconv.Atoi(s) // Convert string to integer
            if err!= nil {
                fmt.Println("Error:", err) // Print any errors encountered
                return
            }
            push(a) // Push the converted integer onto the stack
        }
    }

    // Print the final result which is the last remaining value in the stack
    fmt.Println(pop()) // Print the top value of the stack
}


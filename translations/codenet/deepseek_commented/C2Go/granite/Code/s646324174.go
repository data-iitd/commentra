
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Define the stack slice and top variable
var top int
var S []int

// Function to push an element onto the stack
func push(x int) {
    S = append(S, x)
    top++
}

// Function to pop an element from the stack
func pop() int {
    top--
    return S[top]
}

// Main function to read input, perform operations, and print the result
func main() {
    var a, b int
    var s string
    top = 0 // Initialize the top of the stack

    // Read input from the standard input
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        s = scanner.Text()
        if s[0] == '+' {
            // Pop two elements, add them, and push the result
            b = pop()
            a = pop()
            push(a + b)
        } else if s[0] == '-' {
            // Pop two elements, subtract the top element from the bottom element, and push the result
            b = pop()
            a = pop()
            push(a - b)
        } else if s[0] == '*' {
            // Pop two elements, multiply them, and push the result
            b = pop()
            a = pop()
            push(a * b)
        } else {
            // Convert the input string to an integer and push it onto the stack
            i, _ := strconv.Atoi(s)
            push(i)
        }
    }
    // Print the final result from the stack
    fmt.Println(pop())
}


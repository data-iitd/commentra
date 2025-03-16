package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Global variables
var top int = 0
var S []int

// Function to push an integer onto the stack
func push(x int) {
    S[top] = x
    top++
}

// Function to pop an integer from the stack
func pop() int {
    top--
    return S[top]
}

func main() {
    var a, b int
    var s string
    S = make([]int, 10000)

    // Read input until EOF
    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        s = scanner.Text()
        s = strings.TrimSpace(s)

        // Check for addition operation
        if s[0] == '+' {
            b = pop()
            a = pop()
            push(a + b)
        }
        // Check for subtraction operation
        else if s[0] == '-' {
            b = pop()
            a = pop()
            push(a - b)
        }
        // Check for multiplication operation
        else if s[0] == '*' {
            b = pop()
            a = pop()
            push(a * b)
        }
        // If the input is a number, convert it and push onto the stack
        else {
            push(atoi(s))
        }
    }

    // Print the final result which is the last remaining value in the stack
    fmt.Printf("%d\n", pop())
}


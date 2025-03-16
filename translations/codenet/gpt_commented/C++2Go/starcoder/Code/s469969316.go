package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Global variables for input and state management
var input string
var ss string
var a [3]int
var it int
var cnt int

// Function to compute the NOT operation
func Not(x int) int {
    return 2 - x // Returns the negation of the input value
}

// Function to compute the AND operation
func And(x, y int) int {
    if x*y == 0 {
        return 0 // If either input is 0, return 0
    }
    if x == 2 && y == 2 {
        return 2 // If both inputs are 2, return 2
    }
    return 1 // Otherwise, return 1
}

// Function to compute the OR operation
func Or(x, y int) int {
    if x == 2 || y == 2 {
        return 2 // If either input is 2, return 2
    }
    if x == 1 || y == 1 {
        return 1 // If either input is 1, return 1
    }
    return 0 // Otherwise, return 0
}

// Recursive function to parse the expression and evaluate it
func parse() int {
    c := ss[it] // Get the current character from the string
    if '0' <= c && c <= '2' {
        return c - '0' // Return the numeric value if it's a digit
    }
    if c == '-' {
        return Not(parse()) // Handle NOT operation
    }

    // Parse left operand
    x := parse()
    c = ss[it+1] // Get the operator
    // Parse right operand
    y := parse()
    it += 2 // Move past the closing parenthesis
    // Return the result of the operation based on the operator
    if c == '*' {
        return And(x, y)
    }
    return Or(x, y)
}

// Main function to read input and evaluate expressions
func main() {
    // Loop until the input is a single dot (.)
    for {
        fmt.Scanln(&input)
        if input == "." {
            break
        }

        // Initialize the truth values for P, Q, R
        for i := 0; i < 3; i++ {
            a[i] = i
        }
        cnt = 0 // Initialize the count of valid evaluations

        // Iterate through all combinations of truth values for P, Q, R
        for i := 0; i < 3; i++ {
            for j := 0; j < 3; j++ {
                for k := 0; k < 3; k++ {
                    a[0] = i
                    a[1] = j
                    a[2] = k
                    ss = input

                    // Replace variables P, Q, R in the expression with their truth values
                    for i, c := range ss {
                        if c == 'P' {
                            ss = ss[:i] + string(a[0]+'0') + ss[i+1:]
                        }
                        if c == 'Q' {
                            ss = ss[:i] + string(a[1]+'0') + ss[i+1:]
                        }
                        if c == 'R' {
                            ss = ss[:i] + string(a[2]+'0') + ss[i+1:]
                        }
                    }

                    it = 0 // Reset the index for parsing
                    // Evaluate the expression and count if it evaluates to true (2)
                    if parse() == 2 {
                        cnt++
                    }
                }
            }
        }
        // Output the count of valid evaluations
        fmt.Println(cnt)
    }
}


package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold two integers and a character for the operation
    var a, b int
    var S string

    // Start an infinite loop to continuously accept user input
    for {
        // Read two integers and an operator from the user
        fmt.Scanf("%d %s %d", &a, &S, &b)

        // Perform addition if the operator is '+'
        if S == "+" {
            fmt.Println(a + b)
        }

        // Perform subtraction if the operator is '-'
        if S == "-" {
            fmt.Println(a - b)
        }

        // Perform multiplication if the operator is '*'
        if S == "*" {
            fmt.Println(a * b)
        }

        // Perform division if the operator is '/'
        if S == "/" {
            fmt.Println(a / b)
        }

        // Exit the loop if the operator is '?'
        if S == "?" {
            break
        }
    }
}


package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Initialize a counter variable 'i' to track the case number and an 'Input' variable to store user input
    i := 1
    Input := 0

    // Start an infinite loop to continuously accept user input
    for {
        // Read an integer input from the user
        fmt.Scanf("%d", &Input)

        // Check if the input is zero, which indicates the end of input
        if Input == 0 {
            // Exit the loop if the input is zero
            break
        }

        // Print the case number and the input value
        fmt.Printf("Case %d: %d\n", i, Input)

        // Increment the case number for the next iteration
        i++
    }
}


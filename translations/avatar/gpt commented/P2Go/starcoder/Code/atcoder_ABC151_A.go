package main

import (
    "fmt"
    "os"
    "strings"
)

// Function to log debug messages
func log(text string) {
    if debug {
        fmt.Println(text)
    }
}

// Function to parse input from the user or from a string
func parseInput(linesAsInput string) (c string) {
    var lines []string
    var debug bool

    // Check if input is provided as a string
    if linesAsInput == "" {
        debug = false
        lines = append(lines, readInput())
    } else {
        debug = true
        lines = strings.Split(linesAsInput, "\n")
    }

    // Extract the first element from the first line as the character to process
    c = strings.Split(lines[0], " ")[0]
    return
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) (result string) {
    a := "abcdefghijklmnopqrstuvwxyz"
    i := strings.Index(a, c)
    result = a[i+1]
    return
}

// Main function to execute the program logic
func main() {
    // Parse input and solve the problem
    result := solve(parseInput(os.Args[1]))

    // Check if the result is a list and print each result
    if len(result) > 0 {
        for _, r := range result {
            fmt.Println(r)
        }
    } else {
        // Print the single result
        fmt.Println(result)
    }
}

// Entry point of the program
func main() {
    main()
}


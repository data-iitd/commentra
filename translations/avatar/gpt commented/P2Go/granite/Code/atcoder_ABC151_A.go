
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Flag to enable or disable debugging
var debug = false

// Function to log debug messages
func log(text string) {
    if debug {
        fmt.Println(text)
    }
}

// Function to parse input from the user or from a string
func parseInput(linesAsString string) (string, error) {
    global debug
    lines := []string{}

    // Check if input is provided as a string
    if linesAsString == "" {
        debug = false  // Disable debug mode for standard input
        scanner := bufio.NewScanner(os.Stdin)
        scanner.Scan()
        lines = append(lines, scanner.Text())  // Read input from the user
    } else {
        debug = true  // Enable debug mode for string input
        // Split the input string into lines and ignore the first and last lines
        lines = strings.Split(linesAsString, "\n")[1 : len(strings.Split(linesAsString, "\n"))-1]
    }

    // Extract the first element from the first line as the character to process
    c := strings.Split(lines[0], " ")[0]
    return c, nil
}

// Function to solve the problem by finding the next character in the alphabet
func solve(c string) string {
    a := "abcdefghijklmnopqrstuvwxyz"  // String containing all lowercase letters
    i, _ := strconv.Atoi(fmt.Sprintf("%d", strings.Index(a, c)))  // Find the index of the given character
    return string(a[i+1])  // Return the next character in the alphabet
}

// Main function to execute the program logic
func main() {
    // Parse input and solve the problem
    c, _ := parseInput("")
    result := solve(c)

    // Check if the result is a list and print each result
    if strings.Contains(fmt.Sprintf("%T", result), "[]") {
        for _, r := range result.([]string) {
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

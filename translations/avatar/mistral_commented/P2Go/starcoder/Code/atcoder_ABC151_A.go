package main

import (
    "fmt"
    "os"
    "strings"
)

// Function to parse input lines
func parseInput(lines []string) (string, error) {
    // Extract the first character from the first line as the command
    c := lines[0][0]

    // Return the command as a tuple
    return c, nil
}

// Function to solve the problem based on the command
func solve(c string) string {
    // Define the alphabet string
    a := "abcdefghijklmnopqrstuvwxyz"

    // Find the index of the command character in the alphabet string
    i := strings.Index(a, c)

    // Return the next character in the alphabet string
    return a[i+1]
}

// Main function to execute the code
func main() {
    // Get the input as a list of strings
    lines, err := readInput()
    if err!= nil {
        fmt.Printf("Failed to read input: %v", err)
        os.Exit(1)
    }

    // Get the command from the input
    c, err := parseInput(lines)
    if err!= nil {
        fmt.Printf("Failed to parse input: %v", err)
        os.Exit(1)
    }

    // Solve the problem
    result := solve(c)

    // Print the result
    fmt.Printf("%s", result)
}

// Function to read the input
func readInput() ([]string, error) {
    // Read the input as a single string
    linesAsSingleString, err := readSingleString()
    if err!= nil {
        return []string{}, err
    }

    // Split the lines on newline characters
    lines := strings.Split(linesAsSingleString, "\n")

    // Return the lines as a list of strings
    return lines, nil
}

// Function to read a single string from stdin
func readSingleString() (string, error) {
    // Read a single line from stdin
    result, err := bufio.NewReader(os.Stdin).ReadString('\n')
    if err!= nil {
        return "", err
    }

    // Remove the trailing newline character
    result = strings.TrimSuffix(result, "\n")

    // Return the string
    return result, nil
}


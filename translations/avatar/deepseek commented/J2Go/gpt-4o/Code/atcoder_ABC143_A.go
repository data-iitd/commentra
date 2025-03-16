package main // Defining the main package

import (
    "bufio" // Importing bufio for buffered I/O
    "fmt"   // Importing fmt for formatted I/O
    "os"    // Importing os for standard input
    "strconv" // Importing strconv for string conversion
)

func main() { // Main function where execution begins
    reader := bufio.NewReader(os.Stdin) // Creating a buffered reader to read input
    input, _ := reader.ReadString('\n') // Reading input until a newline
    input = input[:len(input)-1] // Removing the newline character

    x := split(input) // Splitting the input string into an array of strings
    a, _ := strconv.Atoi(x[0]) // Converting the first element of the array to an integer
    b, _ := strconv.Atoi(x[1]) // Converting the second element of the array to an integer
    c := a - b*2 // Performing a mathematical operation to calculate a result
    if c < 0 { // Checking if the result is negative
        c = 0 // Setting it to 0 if true
    }
    fmt.Println(c) // Printing the result to the standard output
}

// Helper function to split a string by spaces
func split(s string) []string {
    return bufio.NewScanner(strings.NewReader(s)).Split(bufio.ScanWords)
}

// <END-OF-CODE>

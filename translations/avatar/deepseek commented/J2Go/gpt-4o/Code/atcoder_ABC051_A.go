package main // Defining the main package

import (
    "bufio" // Importing bufio for buffered I/O
    "fmt"   // Importing fmt for formatted I/O
    "os"    // Importing os for operating system functionalities
    "strings" // Importing strings for string manipulation
)

func main() { // Main function is the entry point of the program
    reader := bufio.NewReader(os.Stdin) // Initializing a buffered reader to read input
    input, _ := reader.ReadString('\n') // Reading a line of input from the user
    output := strings.ReplaceAll(input, ",", " ") // Replacing commas with spaces in the input string
    fmt.Print(output) // Printing the manipulated string
}

// <END-OF-CODE>

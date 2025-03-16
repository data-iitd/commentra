package main  // Declare the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {
    var height, width int  // Declare variables for height and width
    fmt.Scanf("%d %d", &height, &width)  // Read height and width from user input
    inputStr := make([]byte, width)  // Create a byte slice to store the input string

    // Print the top border of the output
    for i := 0; i < width+2; i++ {
        fmt.Print("#")
    }
    fmt.Println()

    // Read and print each line of input with borders
    for i := 0; i < height; i++ {
        fmt.Scanf("%s", &inputStr)  // Read a string from the user
        fmt.Printf("#%s#\n", inputStr)  // Print the string with borders
    }

    // Print the bottom border of the output
    for i := 0; i < width+2; i++ {
        fmt.Print("#")
    }
    fmt.Println()
}

// <END-OF-CODE>

package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var str [21]byte // Declare a byte array named 'str' with a size of 21
    var len int      // Declare an integer variable named 'len'

    fmt.Print("Enter a string: ") // Prompt the user to enter a string
    fmt.Scanf("%s", &str)          // Read a string from the standard input and store it in the 'str' array

    // Calculate the length of the string stored in the 'str' array
    for i := 0; i < len(str); i++ {
        if str[i] == 0 { // Check for the null terminator
            len = i
            break
        }
    }

    fmt.Print("Reversed string: ") // Print a message to indicate that the reversed string will be printed

    for i := len - 1; i >= 0; i-- { // Use a for loop to print each character of the string in reverse order
        fmt.Print(string(str[i])) // Print the character at the index 'i' of the 'str' array
    }

    fmt.Println() // Print a newline character
}

// <END-OF-CODE>

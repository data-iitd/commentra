package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Declare the main function
    var str [30]byte // Declare a byte array str of size 30

    // Get a string input from the user and store it in str array
    fmt.Scanf("%s", &str) // Note: This will read a single word, use bufio for full line input

    // Assign a space character to the 6th index (index starts from 0) and 14th index of the string str
    str[5] = ' '
    str[13] = ' '

    // Print the modified string using fmt.Printf() function
    fmt.Printf("%s\n", str)

    // Return 0 to indicate successful execution of the program
}

// <END-OF-CODE>

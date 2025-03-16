package main // Define the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Define the main function
    var str [30]byte // Declare a byte array to hold the input string
    fmt.Scanf("%s", &str) // Read input from the user

    str[5] = ' ' // Modify the string by replacing the character at position 5 with a space
    str[13] = ' ' // Modify the string by replacing the character at position 13 with a space

    fmt.Println(string(str[:])) // Print the modified string to the console
}

// <END-OF-CODE>

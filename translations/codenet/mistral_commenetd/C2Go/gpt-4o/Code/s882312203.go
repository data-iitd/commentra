package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // The main function is the entry point of the program
    var s string // Declare a string variable 's' to store the input string

    fmt.Scan(&s) // Read a string from the standard input and store it in the 's' variable

    for j := 0; j < len(s); j++ { // Iterate through each character in the string 's' using index 'j'
        for i := 0; i < len(s); i++ { // Nested loop to compare each character with all other characters in the string
            if i != j && s[i] == s[j] { // Check if the current characters at indices 'i' and 'j' are the same and not the same index
                fmt.Println("no") // If duplicate characters are found, print 'no' and exit the program
                return
            }
        }
    }

    fmt.Println("yes") // If no duplicate characters are found, print 'yes'
}

// <END-OF-CODE>

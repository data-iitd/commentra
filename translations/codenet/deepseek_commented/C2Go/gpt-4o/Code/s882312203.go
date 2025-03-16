package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var s string // Declare a string variable to store the input

    fmt.Scan(&s) // Read a string from the user input and store it in the variable s

    // Outer loop to iterate over each character in the string s using index j
    for j := 0; j < len(s); j++ {
        // Inner loop to iterate over each character in the string s using index i
        for i := 0; i < len(s); i++ {
            // Check if the characters at positions i and j are the same, but only if i is not equal to j
            if i != j && s[i] == s[j] {
                fmt.Println("no") // Print "no" if a duplicate character is found and exit the program
                return
            }
        }
    }

    fmt.Println("yes") // Print "yes" if no duplicates are found after completing the loops
}

// <END-OF-CODE>

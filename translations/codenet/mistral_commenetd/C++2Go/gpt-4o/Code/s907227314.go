package main

import (
    "fmt"
)

func main() {
    var s string // Declare a string variable named s to store the user input
    fmt.Scan(&s) // Read a string input from the standard input stream and store it in the s variable

    var a, z int // Declare two integer variables named a and z

    // This for loop iterates through each character in the string s
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' { // Check if the current character is 'A'
            a = i // If it is, assign the index of the character to the variable a
            break // Exit the loop once 'A' is found
        }
    }

    // This for loop iterates through the string in reverse order
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'Z' { // Check if the current character is 'Z'
            z = i // If it is, assign the index of the character to the variable z
            break // Exit the loop once 'Z' is found
        }
    }

    fmt.Println(z - a + 1) // Output the difference between the indices of 'Z' and 'A' plus one
}

// <END-OF-CODE>

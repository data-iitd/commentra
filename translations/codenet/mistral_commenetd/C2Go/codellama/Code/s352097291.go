
package main

import (
    "fmt"
    "strings"
)

func main() {
    // Declare variables
    var c string // An array to store the input string
    var ans string = "" // An array to store the output string

    // Initialize variables
    fmt.Scan(&c) // Read a string from the standard input and store it in the 'c' array

    // Process the string
    for i := 0; i < len(c); i++ { // Iterate through each character in the string 'c'
        if c[i] != 'B' { // If the current character is not 'B'
            ans += string(c[i]) // Append the character to the output string 'ans'
        } else { // If the current character is 'B'
            ans = ans[:len(ans)-1] // Remove the last character from the output string 'ans'
        }
    }

    // Print the output
    fmt.Println(ans) // Print the final output string
}

// The comments explain the purpose of each logical block and make the code more readable.


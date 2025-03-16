package main

import (
    "fmt"
)

func main() {
    // Declare a character array to store input
    var S string

    // Read a string input from the user
    fmt.Scan(&S)

    // Iterate through each character in the string
    for i := 0; i < len(S)-1; i++ {
        // Check if the current character is 'A' and the next character is 'C'
        if S[i] == 'A' && S[i+1] == 'C' {
            // If the condition is met, print "Yes" and exit the program
            fmt.Println("Yes")
            return
        }
    }

    // If the loop completes without finding "AC", print "No"
    fmt.Println("No")
}

// <END-OF-CODE>

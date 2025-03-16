package main

import (
    "fmt"
    "os"
)

func main() {
    var s string
    fmt.Scan(&s) // Reading the input string from the console.
    
    if contains(s, 'A') && contains(s, 'B') { // Checking if the string contains both 'A' and 'B'.
        fmt.Println("Yes") // Printing "Yes" if the condition is true.
    } else {
        fmt.Println("No") // Printing "No" if the condition is false.
    }
}

// contains function checks if a character is present in a string.
func contains(s string, char rune) bool {
    for _, c := range s {
        if c == char {
            return true
        }
    }
    return false
}

// <END-OF-CODE>

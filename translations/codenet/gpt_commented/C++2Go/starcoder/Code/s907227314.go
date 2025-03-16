package main

import (
    "fmt"
    "os"
    "strings"
)

func main() {
    // Declare a string variable to hold the input
    var s string
    
    // Read input string from the user
    fmt.Scanf("%s", &s)
    
    // Declare variables to store the positions of 'A' and 'Z'
    var a, z int
    
    // Loop through the string to find the first occurrence of 'A'
    for i := 0; i < len(s); i++ {
        if s[i] == 'A' {
            a = i // Store the index of 'A'
            break // Exit the loop once 'A' is found
        }
    }
    
    // Loop through the string in reverse to find the last occurrence of 'Z'
    for i := len(s) - 1; i >= 0; i-- {
        if s[i] == 'Z' {
            z = i // Store the index of 'Z'
            break // Exit the loop once 'Z' is found
        }
    }
    
    // Calculate the number of characters between 'A' and 'Z' (inclusive) and print the result
    fmt.Println(z - a + 1)
    
    // Return 0 to indicate successful completion of the program
    os.Exit(0)
}


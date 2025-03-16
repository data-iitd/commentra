package main

import (
    "fmt"
    "strconv"
)

func main() {
    var s string // Declare a string variable for input
    fmt.Scan(&s) // Read a string input from the user

    // Construct the abbreviated version of the string
    t := string(s[0]) // Start with the first character of the input string
    t += strconv.Itoa(len(s) - 2) // Append the number of characters between the first and last characters
    t += string(s[len(s)-1]) // Append the last character of the input string

    fmt.Println(t) // Output the abbreviated string
}

// <END-OF-CODE>

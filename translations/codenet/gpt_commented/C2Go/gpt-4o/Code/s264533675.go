package main

import (
    "fmt"
)

func main() {
    // Declare a string variable to hold user input
    var str string

    // Read a line of input from the user
    fmt.Scanln(&str)

    // Convert the string to a slice of runes to modify specific characters
    runes := []rune(str)

    // Replace the character at index 5 with a space
    if len(runes) > 5 {
        runes[5] = ' '
    }

    // Replace the character at index 13 with a space
    if len(runes) > 13 {
        runes[13] = ' '
    }

    // Print the modified string to the console
    fmt.Println(string(runes))
}

// <END-OF-CODE>

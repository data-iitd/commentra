package main

import (
    "fmt"
    "len"
)

func main() {
    var mes string // Declare a string variable to store the input string
    fmt.Scan(&mes) // Read a string input from the user and store it in 'mes'

    // Calculate the length of the string excluding the first and last character
    length := len(mes) - 2

    // Print the first character, the calculated length, and the last character of the string
    fmt.Printf("%c%v%c\n", mes[0], length, mes[len(mes)-1])
}

// <END-OF-CODE>

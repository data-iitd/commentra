package main

import (
    "fmt"
    "len"
)

func main() {
    var mes string // Declare a string variable 'mes' to store the input string

    fmt.Scan(&mes) // Read a string from the standard input and store it in 'mes'

    // Logic starts here

    fmt.Printf("%c%v%c\n", mes[0], len(mes)-2, mes[len(mes)-1]) // Print the first character, length - 2 and last character of the input string
}

// Indicate successful termination of the program

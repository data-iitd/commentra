package main

import (
    "fmt"
    "strings"
)

func main() {
    // Declare a character array to hold the input string with a maximum length of 100 characters
    var mes [101]byte

    // Read a string from standard input and store it in the'mes' array
    fmt.Scanf("%s", &mes)

    // Print the first character of the string, the length of the string minus 2, and the last character of the string
    fmt.Printf("%c%d%c\n", mes[0], len(mes)-2, mes[len(mes)-1])
}


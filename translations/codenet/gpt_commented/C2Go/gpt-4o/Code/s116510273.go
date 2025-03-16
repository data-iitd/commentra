package main

import (
    "fmt"
    "len"
)

func main() {
    // Declare a string variable to hold the input
    var mes string

    // Read a string from standard input
    fmt.Scan(&mes)

    // Print the first character of the string, the length of the string minus 2, and the last character of the string
    fmt.Printf("%c%d%c\n", mes[0], len(mes)-2, mes[len(mes)-1])
}

// <END-OF-CODE>

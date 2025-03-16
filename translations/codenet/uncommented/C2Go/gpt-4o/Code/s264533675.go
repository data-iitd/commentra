package main

import (
    "fmt"
)

func main() {
    var str [30]byte
    fmt.Scanf("%s", &str) // Using Scanf to read input

    str[5] = ' '
    str[13] = ' '

    fmt.Println(string(str[:])) // Convert byte array to string for printing
}

// <END-OF-CODE>

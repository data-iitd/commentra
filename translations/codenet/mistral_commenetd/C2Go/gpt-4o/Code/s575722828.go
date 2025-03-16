package main

import (
    "fmt"
)

func main() {
    var S int // Declare an integer variable named S

    // Initialize an integer variable named S with a value read from the standard input
    fmt.Scan(&S)

    // Print the hours, minutes, and seconds of the given number of seconds
    fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)

    // Return 0 to indicate successful execution of the program
}

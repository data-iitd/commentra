package main

import (
    "fmt"
)

func main() {
    // Declare an integer variable to hold the input seconds
    var S int

    // Read an integer input from the user representing seconds
    fmt.Scan(&S)

    // Check if the input seconds are less than 60
    if S < 60 {
        // If less than 60 seconds, print the time in the format 0:0:seconds
        fmt.Printf("0:0:%d\n", S)
    } else if S < 3600 {
        // If less than 1 hour, print the time in the format 0:minutes:seconds
        fmt.Printf("0:%d:%d\n", S/60, S%60)
    } else {
        // Print the time in the format hours:minutes:seconds
        fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)
    }
}

// <END-OF-CODE>

package main

import (
    "fmt"
)

func main() {
    var S, W int

    // Get the input as two integers
    fmt.Scan(&S, &W)

    // Check if the condition S <= W is true or false and print the corresponding message
    if S <= W {
        fmt.Println("unsafe")
    } else {
        fmt.Println("safe")
    }
}

// <END-OF-CODE>

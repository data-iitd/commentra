package main

import (
    "fmt"
    "os"
    "strconv"
)

func main() {
    // Declare an integer variable to store user input
    var n int

    // Read an integer value from the user
    fmt.Scanf("%d", &n)

    // Check if the number is even
    if n%2 == 0 {
        // If the number is even, print half of the number
        fmt.Println(n/2)
    } else {
        // If the number is odd, print half of the number plus one
        fmt.Println((n/2)+1)
    }

    // Return 0 to indicate successful execution of the program
    os.Exit(0)
}


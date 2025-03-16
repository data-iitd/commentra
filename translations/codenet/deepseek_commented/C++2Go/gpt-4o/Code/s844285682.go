package main

import (
    "fmt"
)

func main() {
    var a int // Declare an integer variable a

    fmt.Scan(&a) // Take an integer input from the user and store it in variable a

    hours := a / (60 * 60) // Calculate hours
    minutes := (a % (60 * 60)) / 60 // Calculate minutes
    seconds := a % (60 * 60) % 60 // Calculate seconds

    fmt.Printf("%d:%d:%d\n", hours, minutes, seconds) // Output the hours, minutes, and seconds
}

// <END-OF-CODE>

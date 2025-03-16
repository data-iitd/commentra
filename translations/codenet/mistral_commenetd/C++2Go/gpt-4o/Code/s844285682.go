package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var a int // Declare an integer variable named a

    fmt.Print("Enter the number of seconds: ") // Print a message to ask the user for the number of seconds
    fmt.Scan(&a) // Read an integer value from the standard input and assign it to the variable a

    hours := a / (60 * 60) // Extract the hours from the number of seconds
    minutes := (a % (60 * 60)) / 60 // Extract the minutes from the remaining seconds
    seconds := (a % (60 * 60)) % 60 // Extract the seconds from the remaining seconds

    fmt.Printf("%d:%d:%d\n", hours, minutes, seconds) // Print the time representation of the number of seconds
}

// <END-OF-CODE>

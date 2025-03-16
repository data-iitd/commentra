package main // Declaring the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // Main function declaration
    var x int // Declaring an integer variable x
    var y int // Declaring an integer variable y

    fmt.Print("Enter a number: ") // Printing a message to ask user for input
    fmt.Scanf("%d", &x) // Reading an integer value from the user and storing it in variable x

    y = x * x * x // Assigning the value of x cubed to variable y

    fmt.Printf("The cube of %d is %d\n", x, y) // Printing the message with the input number and its cube
}

// <END-OF-CODE>

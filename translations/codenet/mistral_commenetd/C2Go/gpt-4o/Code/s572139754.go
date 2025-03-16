package main // Declaring the main package

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() { // Starting the main function
    var n int // Declaring an integer variable `n` to store the user input

    fmt.Print("Enter a number: ") // Printing a message to ask the user to enter a number
    fmt.Scan(&n) // Reading an integer value from the standard input and storing it in the variable `n`

    if n%1000 == 0 { // Checking if the remainder of `n` when divided by 1000 is equal to 0
        fmt.Println(0) // If the condition is true, we print the value 0 to the standard output
    } else {
        fmt.Println((n/1000+1)*1000 - n) // If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output
    }
}

// <END-OF-CODE>

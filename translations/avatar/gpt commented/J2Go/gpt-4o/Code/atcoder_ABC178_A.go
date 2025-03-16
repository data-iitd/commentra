package main

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() {
    // Reading an integer input from the user
    var x int
    fmt.Scan(&x)

    // Using a conditional statement to determine the boolean value based on the input
    var boolValue bool = (x == 1)

    // Setting the result based on the boolean value; if boolValue is false, result is 1, otherwise 0
    var result int
    if !boolValue {
        result = 1
    } else {
        result = 0
    }

    // Printing the result to the console
    fmt.Println(result)
}

// <END-OF-CODE>


package main

import (
    "fmt" // Importing the 'fmt' package for formatted I/O
)

func main() {
    // Declaring a variable 'data' of type 'int' to read user input
    var data int

    // Reading user input and storing it in the 'data' variable
    fmt.Scan(&data)

    // Declaring a variable 'result' of type 'int' to store the result
    var result int

    // Assigning the value of 'data' cubed to the 'result' variable
    result = data * data * data

    // Printing the result using the 'Printf' function from 'fmt' package
    fmt.Printf("%d\n", result) // Printing the result with format specifier '%d' and newline character '\n'
}


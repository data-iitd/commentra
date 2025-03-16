package main

import (
    "fmt" // Importing the fmt package for formatted I/O
)

func main() {
    var data int // Declare a variable to hold the input integer
    fmt.Scan(&data) // Read an integer value from standard input and store it in 'data'
    
    var result = data * data * data // Calculate the cube of the input value
    fmt.Printf("%d\n", result) // Print the result to standard output
}

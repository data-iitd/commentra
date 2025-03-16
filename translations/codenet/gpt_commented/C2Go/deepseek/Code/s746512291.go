package main

import "fmt" // Import the fmt package for formatted I/O operations

func main() {
    var x int // Declare an integer variable x

    // Prompt the user for input and read an integer value into x
    fmt.Scan(&x)

    // Calculate the cube of x and print the result
    fmt.Println(x * x * x)
}


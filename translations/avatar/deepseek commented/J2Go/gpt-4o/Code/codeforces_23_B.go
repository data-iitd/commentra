package main // Defining the main package

import (
    "fmt" // Importing the fmt package for input and output operations
)

func main() { // The main function, the entry point of the program
    var t int
    fmt.Scan(&t) // Reading the number of test cases
    for i := 0; i < t; i++ { // Looping through each test case
        var n int
        fmt.Scan(&n) // Reading the value of n for each test case
        fmt.Println(maxLeft(n)) // Calling the maxLeft function and printing the result
    }
}

func maxLeft(n int) int { // Defining the maxLeft function
    if n > 2 { // Checking if n is greater than 2
        return n - 2 // Returning n - 2 if true
    }
    return 0 // Returning 0 if false
}

// <END-OF-CODE>

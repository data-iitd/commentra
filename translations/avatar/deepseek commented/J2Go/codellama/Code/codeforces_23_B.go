
Here are the comments for each logical block in the code:

package main

import "fmt"

func main() { // Defining the main function, the entry point of the program
    var t int // Declaring a variable t to store the number of test cases
    fmt.Scan(&t) // Reading the number of test cases
    for i := 0; i < t; i++ { // Looping through each test case
        var n int // Declaring a variable n to store the value of n for each test case
        fmt.Scan(&n) // Reading the value of n for each test case
        fmt.Println(maxLeft(n)) // Calling the maxLeft function and printing the result
    }
}

func maxLeft(n int) int { // Defining the maxLeft function
    if n > 2 { // Checking if n is greater than 2
        return n - 2 // Returning n - 2 if n is greater than 2
    }
    return 0 // Returning 0 otherwise
}


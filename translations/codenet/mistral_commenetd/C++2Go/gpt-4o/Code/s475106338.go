package main // Declare the main package

import (
    "fmt" // Import the fmt package for input/output operations
)

func main() { // The main function is the entry point of the program
    var t, n int // Declare two integer variables: t for user input and n for the number of items

    // The for loop runs 4 times, each time reading user input and processing it accordingly
    for i := 0; i < 4; i++ {
        fmt.Scan(&t, &n) // Read two integers from the user: t and n

        // Check the value of t and process the input accordingly
        if t == 1 {
            fmt.Println(6000 * n) // If t is 1, print the result of multiplying n by 6000
        } else if t == 2 {
            fmt.Println(4000 * n) // If t is 2, print the result of multiplying n by 4000
        } else if t == 3 {
            fmt.Println(3000 * n) // If t is 3, print the result of multiplying n by 3000
        } else if t == 4 {
            fmt.Println(2000 * n) // If t is 4, print the result of multiplying n by 2000
        }
    }
}

// <END-OF-CODE>

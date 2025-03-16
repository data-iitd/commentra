package main

import "fmt"

func main() {
    // Declare two integer variables a and b
    var a, b int

    // Read two integers from user input
    fmt.Scan(&a, &b)

    // Calculate and print the result of the expression
    // The expression computes the number of complete groups of (a-1) that can fit into (b-1) + (a-2)
    result := ((b - 1) + (a - 2)) / (a - 1)
    fmt.Println(result)

    // Return 0 to indicate successful execution of the program
}


package main

import "fmt"

func main() {
    // Declare variables to hold two integers and their average
    var a, b, n int

    // Read two integers from user input
    fmt.Scan(&a, &b)

    // Calculate the average of the two integers
    n = (a + b) / 2

    // Print the calculated average
    fmt.Println(n)
}


package main

import (
    "fmt"
)

func main() {
    var A, B int // Declare two integer variables A and B
    fmt.Scan(&A, &B) // Read the values of A and B from the standard input

    if A < 13 && A >= 6 { // Check if A is within the range of 6 to 12 (inclusive)
        fmt.Println(B / 2) // If true, divide B by 2 and print the result to the standard output
    }

    if A < 6 { // Check if A is less than 6
        fmt.Println(0) // If true, print 0 to the standard output
    }

    if A >= 13 { // Check if A is greater than or equal to 13
        fmt.Println(B) // If true, print B to the standard output
    }
}

// <END-OF-CODE>

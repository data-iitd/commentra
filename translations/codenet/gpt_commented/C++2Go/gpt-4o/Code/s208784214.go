package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var N, A int // Declare two integer variables N and A

    // Read two integers from standard input
    fmt.Scan(&N, &A)

    // Check if the remainder of N divided by 500 is less than or equal to A
    // If true, print "Yes"; otherwise, print "No"
    if N%500 <= A {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}

// <END-OF-CODE>

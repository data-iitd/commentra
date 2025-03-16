package main

import (
    "fmt"
)

func main() {
    // Declare variables to hold three strings
    var A, B, C string

    // Read three strings from user input
    fmt.Scan(&A, &B, &C)

    // Calculate the lengths of the first two strings
    la := len(A)
    lb := len(B)

    // Check if the last character of A is the same as the first character of B
    // and if the last character of B is the same as the first character of C
    if A[la-1] == B[0] && B[lb-1] == C[0] {
        // If both conditions are true, print "YES"
        fmt.Println("YES")
    } else {
        // If either condition is false, print "NO"
        fmt.Println("NO")
    }
}

// <END-OF-CODE>

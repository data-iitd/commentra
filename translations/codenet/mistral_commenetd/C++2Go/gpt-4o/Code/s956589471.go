package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var a, b, c, d, e, k int // Declare and initialize six integer variables

    // Read the values of these variables from the standard input using fmt.Scan
    fmt.Scan(&a, &b, &c, &d, &e, &k)

    // Perform a simple condition check using the relational operator <=
    if e-a <= k {
        fmt.Println("Yay!") // If the condition is true, print "Yay!" to the standard output
    } else {
        fmt.Println(":(") // If the condition is false, print ":" and a sad face "(" to the standard output
    }
}

// <END-OF-CODE>

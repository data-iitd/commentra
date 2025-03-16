package main // Declare the main package

import (
    "fmt" // Import the fmt package for input and output
)

func main() {
    var a, b, c int // Declare three integer variables to hold the input values
    fmt.Scan(&a, &b, &c) // Read three integers from the user

    // Check if 'a' is greater than 'b', if so, swap their values
    if a > b {
        a, b = b, a
    }

    // Check if 'b' is greater than 'c', if so, swap their values
    if b > c {
        b, c = c, b
    }

    // Check again if 'a' is greater than 'b', if so, swap their values
    if a > b {
        a, b = b, a
    }

    // Output the sorted values of a, b, and c
    fmt.Println(a, b, c)
}

// <END-OF-CODE>

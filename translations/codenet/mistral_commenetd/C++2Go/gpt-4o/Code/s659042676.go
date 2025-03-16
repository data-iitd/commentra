package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var a, b int // Declare two integer variables `a` and `b`

    // Read two integer values from the standard input using `Scan`
    fmt.Scan(&a, &b)

    // Calculate the difference between `6` and the sum of `a` and `b`
    result := 6 - a - b

    // Print the result to the standard output using `Println`
    fmt.Println(result)
}

// <END-OF-CODE>

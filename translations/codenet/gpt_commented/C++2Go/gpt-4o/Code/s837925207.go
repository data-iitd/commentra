package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var x int // Declare a variable x for input
    var ans int // Declare a variable ans for the result

    // Read an integer input from the user
    fmt.Scan(&x)

    // Calculate the result as the sum of x, x squared, and x cubed
    ans = x + x*x + x*x*x

    // Output the calculated result to the console
    fmt.Println(ans)
}

// <END-OF-CODE>

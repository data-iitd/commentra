package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Entry point of the program
    var n, k int // Declare two integer variables n and k
    fmt.Scan(&n) // Read the first integer n from standard input
    fmt.Scan(&k) // Read the second integer k from standard input
    n++ // Increment the value of n by 1
    z := 0 // Initialize an integer variable z to 0
    if n%k != 0 { // Check if the remainder of n divided by k is not equal to 0
        z = k - n%k // If the remainder is not equal to 0, calculate the difference and assign it to z
    }
    fmt.Println(n + z) // Print the value of n plus the value of z
}

// <END-OF-CODE>

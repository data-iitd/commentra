package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() {
    var n, k int // Declare two integer variables
    fmt.Scanf("%d%d", &n, &k) // Read two integers from standard input
    if n%k == 0 { // Check if n is divisible by k
        fmt.Println("0") // If true, print 0
    } else {
        fmt.Println("1") // If false, print 1
    }
} // End of main function
// <END-OF-CODE>

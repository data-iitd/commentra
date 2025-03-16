package main // Declare the main package

import "fmt" // Import the fmt package for formatted I/O

func main() {
    var m1, d1, m2, d2 int // Declare four integer variables to store month and day values
    fmt.Scan(&m1, &d1, &m2, &d2) // Read four integer values from the standard input
    if m1 != m2 { // Check if the values of m1 and m2 are not equal
        fmt.Println("1") // If true, print 1
    } else {
        fmt.Println("0") // If m1 and m2 are equal, print 0
    }
}

// <END-OF-CODE>

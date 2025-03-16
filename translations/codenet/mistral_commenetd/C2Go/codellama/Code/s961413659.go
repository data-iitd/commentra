package main

import "fmt"

func main() {
    var a, b int // Declare two integer variables 'a' and 'b'
    fmt.Scan(&a, &b) // Read two integers from the standard input and store them in variables 'a' and 'b'

    // First if block: If 'a' is equal to 1, assign 14 to 'a'
    if a == 1 {
        a = 14
    }

    // Second if block: If 'b' is equal to 1, assign 14 to 'b'
    if b == 1 {
        b = 14
    }

    // Determine who wins based on the values of 'a' and 'b'
    if a < b {
        fmt.Println("Bob") // If 'a' is less than 'b', print "Bob"
    } else if a > b {
        fmt.Println("Alice") // If 'a' is greater than 'b', print "Alice"
    } else {
        fmt.Println("Draw") // If 'a' is equal to 'b', print "Draw"
    }
}


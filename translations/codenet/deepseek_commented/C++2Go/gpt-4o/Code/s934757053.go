package main

import (
    "fmt"
)

func main() {
    var A, B int
    ans := 0
    out := 1 // Initialize out to 1

    fmt.Scan(&A, &B) // Read two integers A and B from the standard input

    for out < B { // Continue the loop as long as out is less than B
        out--      // Decrement out by 1
        out += A   // Increment out by A
        ans++      // Increment ans by 1
    }
    fmt.Println(ans) // Print the value of ans to the standard output
}

// <END-OF-CODE>

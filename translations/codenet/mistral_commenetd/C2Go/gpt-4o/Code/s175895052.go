package main

import (
    "fmt"
)

func main() {
    var n string // Declare a string variable to store the input

    // Read a string from standard input
    fmt.Scan(&n)

    // Check if the first three characters of the input string form an identical sequence
    if (len(n) >= 4 && ((n[0] == n[1] && n[1] == n[2]) || (n[1] == n[2] && n[2] == n[3]))) {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}

// <END-OF-CODE>

package main

import "fmt"

func main() {
    // Declare two integer variables to hold the input values
    var a, b int

    // Read two integers from the user input
    fmt.Scanf("%d %d", &a, &b)

    // Check if 500 times the value of 'a' is greater than or equal to 'b'
    if 500 * a >= b {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}


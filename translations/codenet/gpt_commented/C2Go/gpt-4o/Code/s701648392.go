package main

import (
    "fmt"
)

func main() {
    // Declare three integer variables to hold the input values
    var a, b, c int

    // Read three integers from the user
    fmt.Scanf("%d %d %d", &a, &b, &c)

    // Check if the first number is less than the second and the second is less than the third
    if a < b && b < c {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}

// <END-OF-CODE>

package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare three integer variables to hold input values
    var a, b, c int

    // Read three integers from standard input
    fmt.Scanf("%d %d %d", &a, &b, &c)

    // Check if the sum of a and b is greater than or equal to c
    if a+b >= c {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}


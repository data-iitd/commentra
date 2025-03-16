package main

import "fmt"

func main() {
    // Declare three integer variables to hold the input values
    var a, b, c int

    // Read three integers from standard input
    fmt.Scanf("%d %d %d", &a, &b, &c)
    
    // Check if the first number is less than the second, and the second is less than the third
    if a < b && b < c {
        fmt.Println("Yes") // If the condition is true, print "Yes"
    } else {
        fmt.Println("No")  // If the condition is false, print "No"
    }
}


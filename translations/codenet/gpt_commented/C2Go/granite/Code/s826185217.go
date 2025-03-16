
package main

import "fmt"

func main() {
    // Declare four integer variables to hold input values
    var a, b, c, d int

    // Read four integers from user input
    fmt.Scan(&a, &b, &c, &d)

    // Compare the sum of the first two integers (a and b) with the sum of the last two integers (c and d)
    if a+b > c+d {
        // If the sum of a and b is greater, print "Left"
        fmt.Println("Left")
    } else if a+b < c+d {
        // If the sum of a and b is less, print "Right"
        fmt.Println("Right")
    } else {
        // If both sums are equal, print "Balanced"
        fmt.Println("Balanced")
    }
}


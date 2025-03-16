
package main

import "fmt"

func main() {
    // Declare three integer variables to hold input values
    var a, b, c int

    // Read three integers from standard input
    fmt.Scan(&a, &b, &c)

    // Calculate the value of d as the difference between c and the sum of a and b
    d := c - a - b

    // Check if d is positive and if 4 times the product of a and b is less than d squared
    if (d > 0) && ((4 * a * b) < d * d) {
        // If the condition is true, print "Yes"
        fmt.Println("Yes")
    } else {
        // If the condition is false, print "No"
        fmt.Println("No")
    }
}


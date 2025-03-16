
package main

import "fmt"

func main() {
    // Declare variables to hold two integers and the result
    var a, b, s int

    // Read two integers from user input
    fmt.Scan(&a, &b)

    // Calculate the result using the formula: (a*b) - (a + b) + 1
    s = (a * b) - (a + b) + 1

    // Output the result to the console
    fmt.Println(s)
}


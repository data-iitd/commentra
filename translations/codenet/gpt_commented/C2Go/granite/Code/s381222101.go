
package main

import "fmt"

func main() {
    // Declare variables to hold the lengths of the two bases (a and b) and the height (h)
    var a, b, h int

    // Read the values of the two bases and the height from user input
    fmt.Scan(&a, &b, &h)

    // Calculate the area of the trapezoid using the formula: Area = ((base1 + base2) * height) / 2
    // and print the result
    fmt.Println((a + b) * h / 2)
}


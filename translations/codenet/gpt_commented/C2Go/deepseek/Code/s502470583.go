package main

import "fmt"

func main() {
    // Declare integer variables to hold the input values and results
    var a, b, c, d int

    // Read two integer values from user input
    fmt.Scan(&a, &b)

    // Calculate the area of a rectangle (length * width)
    c = a * b

    // Calculate the perimeter of a rectangle (2 * (length + width))
    d = 2 * a + 2 * b

    // Output the calculated area and perimeter
    fmt.Println(c, d)
}


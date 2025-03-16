package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare integer variables to hold the input values and results
    var a, b, c, d int

    // Read two integer values from user input
    fmt.Scanf("%d %d", &a, &b)

    // Calculate the area of a rectangle (length * width)
    c = a * b

    // Calculate the perimeter of a rectangle (2 * (length + width))
    d = 2 * a + 2 * b

    // Output the calculated area and perimeter
    fmt.Printf("%d %d\n", c, d)

    // Return 0 to indicate successful completion of the program
    os.Exit(0)
}


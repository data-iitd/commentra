package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables to hold the dimensions and results
    var a, b, ar, le int

    // Read the length and width from user input
    fmt.Scanf("%d %d", &a, &b)

    // Calculate the area of the rectangle (length * width)
    ar = a * b

    // Calculate the perimeter of the rectangle (2 * (length + width))
    le = 2 * (a + b)

    // Output the calculated area and perimeter
    fmt.Printf("%d %d\n", ar, le)

    // Return 0 to indicate successful execution
    os.Exit(0)
}


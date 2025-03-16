package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
    "math" // Import the math package for mathematical constants and functions
)

func main() {
    var r float64 // Declare a variable 'r' of type float64

    // Read a value for 'r' from standard input
    fmt.Scanf("%f", &r)

    // Calculate the area and circumference of a circle with radius 'r'
    area := r * r * math.Pi
    circumference := 2 * math.Pi * r

    // Print the results to standard output
    fmt.Printf("%f %f\n", area, circumference)
}

// <END-OF-CODE>

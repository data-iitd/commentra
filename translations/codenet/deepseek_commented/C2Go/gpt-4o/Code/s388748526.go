package main

import (
    "fmt"
    "math"
)

func main() {
    var r float64
    // Read the input value for the radius of the circle
    fmt.Scanf("%f", &r)

    // Calculate the area of the circle (πr^2) and the circumference (2πr)
    area := r * r * math.Pi
    circumference := 2 * math.Pi * r

    // Print the results to the standard output
    fmt.Printf("%f %f\n", area, circumference)
}

// <END-OF-CODE>

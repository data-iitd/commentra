package main // Declare the main package

import (
    "fmt" // Import the fmt package for formatted I/O
)

func main() { // Start of the main function
    var r float64 // Declare a variable 'r' of type float64
    var s, l float64 // Declare two variables 's' and 'l' of type float64
    const p = 3.141592653589 // Initialize a constant variable 'p' with the value of pi

    fmt.Scanf("%lf", &r) // Read a value of type float64 from the standard input and store it in variable 'r'

    s = r * r * p // Calculate the area of a circle with radius 'r' and store it in variable 's'
    l = 2 * p * r // Calculate the circumference of a circle with radius 'r' and store it in variable 'l'

    fmt.Printf("%f %f\n", s, l) // Print the values of 's' and 'l' to the standard output
}

// <END-OF-CODE>

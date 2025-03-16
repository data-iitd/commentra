package main  // Declare the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {
    var n int  // Declare an integer variable 'n' to store the number of sides of the polygon
    fmt.Scan(&n)  // Read the number of sides from user input

    // Calculate the sum of the interior angles of a polygon with 'n' sides
    // The formula for the sum of interior angles is (n - 2) * 180
    fmt.Println((n - 2) * 180)  // Output the calculated sum of interior angles
}

// <END-OF-CODE>

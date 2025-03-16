package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
    var a, b int  // Declare integer variables
    fmt.Scanf("%d %d", &a, &b)  // Read input values
    n := (a + b) / 2  // Calculate the average
    fmt.Println(n)  // Print the result
}  // End of main function

// <END-OF-CODE>

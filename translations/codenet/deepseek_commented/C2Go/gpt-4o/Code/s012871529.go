package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
    var a, b int  // Declare two integer variables
    fmt.Scanf("%d %d", &a, &b)  // Read two integers from the user
    fmt.Printf("%d %d\n", a*b, 2*(a+b))  // Perform calculations and print the results
}  // End of the main function

// <END-OF-CODE>

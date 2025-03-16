package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function, the entry point of the program
    var a, b, c int  // Declare three integer variables
    fmt.Scanf("%d%d%d", &a, &b, &c)  // Read three integer inputs from the user and store them in a, b, and c
    if a < b && b < c {  // Check if a is less than b and b is less than c
        fmt.Println("Yes")  // If true, print "Yes"
    } else {  // Otherwise
        fmt.Println("No")  // Print "No"
    }
}  // End of main function
// <END-OF-CODE>

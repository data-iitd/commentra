package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
    var i, N, x int  // Declare integer variables
    x = 0  // Initialize the variable x to 0
    fmt.Scan(&N)  // Read input from the user and store it in N
    for i = 1; i <= N; i++ {  // Loop through numbers from 1 to N
        x += i  // Add each number to x
    }
    fmt.Println(x)  // Print the final value of x
}  // End of main function

// <END-OF-CODE>

package main  // Define the main package

import (  // Import necessary packages
    "fmt"  // Import the fmt package for formatted I/O
)

func main() {  // Define the main function
    var x, a int  // Declare integer variables
    fmt.Scanf("%d %d", &x, &a)  // Read input values
    fmt.Println((boolToInt(x >= a)) * 10)  // Perform a comparison and multiplication, then print the result
}

// boolToInt converts a boolean value to an integer (1 for true, 0 for false)
func boolToInt(b bool) int {
    if b {
        return 1
    }
    return 0
}


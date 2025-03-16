package main  // Define the main package

import "fmt"  // Import the fmt package for formatted I/O

func main() {  // Define the main function
    var n, b uint64  // Declare variables to store the input number and the result
    fmt.Scanf("%d", &n)  // Read the input number
    b = (n * (n - 1)) / 2  // Calculate the result using the given formula
    fmt.Printf("%d\n", b)  // Print the result
}  // Indicate that the program ended successfully

// <END-OF-CODE>

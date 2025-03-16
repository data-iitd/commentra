package main

import "fmt"  // Import the fmt package for formatted I/O

func main() {  // Define the main function
    var a, b int  // Declare two integer variables
    fmt.Scan(&a, &b)  // Read two integers from the user
    fmt.Println(a * b, 2 * (a + b))  // Perform calculations and print the results
}


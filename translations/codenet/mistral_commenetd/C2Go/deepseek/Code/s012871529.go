package main

import "fmt" // Import the format package for formatted I/O

func main() { // Start of the main function
    var a, b int // Declare two integer variables 'a' and 'b'

    fmt.Scan(&a, &b) // Read two integers from the standard input and store them in variables 'a' and 'b'

    fmt.Println(a*b, 2*(a+b)) // Print the product of 'a' and 'b' followed by the double of their sum
}


package main // Declare the main package

import "fmt" // Import the fmt package for formatted I/O

func main() { // Start of the main function
    var a, b int // Declare two integer variables 'a' and 'b'

    fmt.Scanf("%d %d", &a, &b) // Read two integers from standard input and store them in variables 'a' and 'b'

    fmt.Printf("%d %d\n", a*b, 2*(a+b)) // Print the product of 'a' and 'b' followed by the double of their sum
}

// <END-OF-CODE>

package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() {
	var n, m int // Declare two integer variables to store input values
	fmt.Scanf("%d %d", &n, &m) // Read two integers from standard input and store them in n and m
	fmt.Println((n - 1) * (m - 1)) // Print the result of the expression (n - 1) * (m - 1)
} // End of main function
// <END-OF-CODE>

package main // Declare the main package

import "fmt" // Import the fmt package for formatted I/O

func main() { // Start of the main function
	var a, b, x, y int // Declare four integer variables: a, b, x, and y

	fmt.Scanf("%d%d", &a, &b) // Read two integers from standard input and store them in variables a and b

	x = 2*a + 2*b // Multiply variables a and b by 2, and then add the results together and store the result in variable x

	y = a * b // Multiply variables a and b and store the result in variable y

	fmt.Printf("%d %d\n", y, x) // Print the values of variables y and x to standard output, separated by a space and followed by a newline character
}

// Indicate that the main function has run successfully and terminate the program

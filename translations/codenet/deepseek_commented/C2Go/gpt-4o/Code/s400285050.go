package main  // Declare the main package

import (
	"fmt"  // Import the fmt package for formatted I/O
)

func you(x int, y int) int {  // Define the you function
	var z int  // Declare a variable to store intermediate results
	for {  // Infinite loop to apply the Euclidean algorithm
		z = x % y  // Compute the remainder of x divided by y
		x = y  // Update x to be the previous value of y
		y = z  // Update y to be the remainder
		if y <= 0 {  // Check if y is zero or negative
			break  // Exit the loop if y is zero or negative
		}
	}
	return x  // Return the GCD of the original two numbers
}

func main() {  // Main function is the entry point of the program
	var x, y, z int  // Declare three integer variables
	fmt.Scanf("%d %d", &x, &y)  // Read two integers from standard input
	if x >= y {  // Check if x is greater than or equal to y
		z = you(x, y)  // Call the you function with x and y as arguments
	} else {  // Otherwise
		z = you(y, x)  // Call the you function with y and x as arguments
	}
	fmt.Println(z)  // Print the result to standard output
}

// <END-OF-CODE>

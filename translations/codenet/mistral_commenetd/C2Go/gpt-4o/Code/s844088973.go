package main // Declare the main package

import (
	"fmt" // Import the fmt package for formatted I/O
)

func main() { // Start of the main function
	var K, X int // Declare two integer variables K and X
	fmt.Scanf("%d %d", &K, &X) // Read two integers from the standard input and store them in variables K and X

	for i := X - K + 1; i <= X + K - 1; i++ { // Start of the for loop
		fmt.Print(i) // Print the current value of i to the standard output
		if i < X+K-1 { // If the current value of i is less than X+K-1
			fmt.Print(" ") // Print a space before the next number
		}
	}

	fmt.Println() // Print a newline character to move the cursor to the next line
} // End of the main function
// <END-OF-CODE>

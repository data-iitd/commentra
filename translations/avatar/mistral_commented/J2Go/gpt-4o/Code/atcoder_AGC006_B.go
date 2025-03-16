package main // Declaring the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() { // Main function to start the execution of the program
	var n, x int // Declaring variables n and x
	fmt.Scan(&n) // Reading the first integer input from the user
	fmt.Scan(&x) // Reading the second integer input from the user
	printResult(x, n) // Calling the printResult function with x and n as arguments
}

func printResult(x, n int) { // Function to print the answer based on the given input
	max := n*2 - 1 // Calculating the maximum index for the sequence

	if x == 1 || x == max { // Checking if x is the first or last index in the sequence
		fmt.Println("No") // If true, print "No" and return
		return
	}

	fmt.Println("Yes") // If false, print "Yes"
	for i := x + n - 1; i < x+n+max-1; i++ { // Looping through the range from x+n-1 to x+n+max-1
		fmt.Println((i%max + 1)) // Printing the next integer in the sequence
	}
}

// <END-OF-CODE>

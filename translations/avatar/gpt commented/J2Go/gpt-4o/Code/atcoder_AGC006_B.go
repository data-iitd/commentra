package main

import (
	"fmt"
)

func main() {
	var n, x int
	// Reading two integers from user input: n and x
	fmt.Scan(&n, &x)

	// Calling the print function with the inputs x and n
	print(x, n)
}

func print(x, n int) {
	// Calculating the maximum value based on n
	max := n*2 - 1

	// Checking if x is equal to 1 or max, if so, print "No" and exit the function
	if x == 1 || x == max {
		fmt.Println("No")
		return // Exit the function early
	}

	// If x is valid, print "Yes"
	fmt.Println("Yes")

	// Generate a sequence of numbers based on the input x and n
	for i := x + n - 1; i < x+n+max-1; i++ {
		// Adjusting the number to fit within the range and print it
		fmt.Print((i%max + 1), "\n")
	}
}

// <END-OF-CODE>

// Package declaration
package main

// Importing the required package
import "fmt"

// Function definition for the main function
func main() {
	// Declaring variables r, D, and x of type int
	var r, D, x int

	// Reading input values for r, D, and x from the standard input
	fmt.Scan(&r, &D, &x)

	// Comment for the for loop
	// Loop runs 10 times
	for i := 1; i <= 10; i++ {
		// Print the result of the current iteration
		fmt.Println(r * x - D)

		// Update the value of x for the next iteration
		x = r * x - D
	}
}

// End of the code

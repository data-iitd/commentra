package main

import "fmt"

func main() {
	// Declare variables for radius (r), distance (d), and initial value (x)
	var r, d, x int
	
	// Read input values for r, d, and x from standard input
	fmt.Scanf("%d %d %d", &r, &d, &x)

	// Loop 10 times to perform calculations based on the input values
	for i := 0; i < 10; i++ {
		// Update x using the formula: x = r * x - d
		x = r*x - d
		
		// Print the updated value of x to the standard output
		fmt.Println(x)
	}
}


package main

import "fmt"

func main() {
	// Initialize variables r, d, and x with given values
	var r, d, x int
	fmt.Scanf("%d %d %d", &r, &d, &x)

	// Loop through 10 iterations
	for i := 0; i < 10; i++ {
		// Calculate new value of x using given formula
		x = r*x - d

		// Print the current value of x
		fmt.Println(x)
	}
}


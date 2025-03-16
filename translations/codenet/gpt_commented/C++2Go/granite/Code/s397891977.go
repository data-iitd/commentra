
package main

import (
	"fmt"
	"os"
)

func main() {
	var r int // Declare an integer variable 'r' to store the radius

	// Read the radius value from user input
	fmt.Fscan(os.Stdin, &r)

	// Calculate the area of the circle using the formula πr²
	// Here, we are using the simplified version by omitting π for demonstration
	area := r * r // Calculate the area (r squared)

	// Output the calculated area
	fmt.Println(area)

	// End the program
	os.Exit(0)
}


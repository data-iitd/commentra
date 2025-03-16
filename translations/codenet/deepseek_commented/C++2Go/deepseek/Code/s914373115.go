package main

import (
	"fmt"
)

// Function B is defined to take input and calculate the number of iterations.
func B() {
	var x, sum int
	fmt.Scan(&x)
	i := 0 // Initialize i to 0
	sum = 100 // Initialize sum to 100
	for ; sum < x; i++ {
		sum += sum / 100 // Increment sum by 1%
	}
	fmt.Println(i) // Output the number of iterations
}

// Main function calls the B function.
func main() {
	B()
}


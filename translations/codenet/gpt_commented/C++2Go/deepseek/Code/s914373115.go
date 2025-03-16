package main

import (
	"fmt"
)

// Function declarations
func A()
func B()
func C()
func D()

func main() {
	// Call function B to execute its logic
	B()
}

func B() {
	var x, sum int64 // Declare variables for input and sum
	fmt.Scan(&x) // Read input value x from the user
	var i int // Declare a counter variable
	sum = 100 // Initialize sum to 100

	// Loop until sum is less than x
	for ; sum < x; i++ {
		// Increase sum by 1% of its current value
		sum += sum / 100
	}

	// Output the number of iterations needed to exceed or meet x
	fmt.Println(i)
}


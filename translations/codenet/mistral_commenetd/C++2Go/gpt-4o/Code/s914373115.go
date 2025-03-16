package main

import (
	"fmt"
)

func A() {
	// Function A implementation goes here
}

func B() {
	var x, sum int64 // Declare variables 'x' and 'sum' of type int64
	fmt.Scan(&x)     // Read a long long integer 'x' from the standard input
	var i int        // Declare variable 'i' of type int
	sum = 100        // Initialize 'sum' with the value 100

	// Calculate the number of iterations required to reach or exceed 'x'
	for sum < x {
		sum += sum / 100 // Update 'sum' by adding the result of dividing 'sum' by 100
		i++              // Increment the iteration counter
	}

	// Print the number of iterations required to reach or exceed 'x'
	fmt.Println(i)
}

func C() {
	// Function C implementation goes here
}

func D() {
	// Function D implementation goes here
}

func main() {
	// Call function B
	B()
}

// <END-OF-CODE>

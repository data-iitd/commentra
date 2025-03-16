package main

import (
	"fmt"
)

// Function A definition goes here
func A() {
}

// Function B definition goes here
func B() {
	// Declare variables 'x' and 'sum' of type int
	var x, sum int
	// Read a long long integer 'x' from the standard input
	fmt.Scan(&x)
	// Declare variable 'i' of type int
	var i int
	// Initialize 'sum' with the value 100
	sum = 100

	// Calculate the number of iterations required to reach or exceed 'x'
	for sum < x {
		sum += sum / 100
		i++
	}

	// Print the number of iterations required to reach or exceed 'x'
	fmt.Println(i)
}

// Function C definition goes here
func C() {
}

// Function D definition goes here
func D() {
}

func main() {
	// Call function B
	B()
}


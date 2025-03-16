
package main

import (
	"fmt"
)

// Function A definition goes here
func A() {

}

// Function B definition goes here
func B() {
	var x int64 // Declare variable 'x' of type int64
	var sum int64 // Declare variable 'sum' of type int64
	var i int // Declare variable 'i' of type int

	fmt.Scan(&x) // Read an int64 'x' from the standard input
	sum = 100 // Initialize 'sum' with the value 100

	// Calculate the number of iterations required to reach or exceed 'x'
	for i = 0; sum < x; i++ {
		sum += sum / 100 // Update 'sum' by adding the result of dividing 'sum' by 100
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


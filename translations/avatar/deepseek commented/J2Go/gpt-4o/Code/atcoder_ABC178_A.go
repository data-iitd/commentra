package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x) // Read an integer from the input
	boolValue := x == 1 // Convert the integer x to a boolean value
	result := 0 // Initialize result
	if !boolValue {
		result = 1 // Set result to 1 if boolValue is false
	} else {
		result = 0 // Set result to 0 if boolValue is true
	}
	fmt.Println(result) // Print the result
}

// <END-OF-CODE>

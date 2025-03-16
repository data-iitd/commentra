package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	a := make([]int, n) // Initialize slice 'a' to store first set of values
	b := make([]int, n) // Initialize slice 'b' to store second set of values
	temp := 0 // Variable to temporarily store a value
	q := 0 // Variable to store a value for comparison
	w := 0 // Variable to store the maximum value of 'a'
	e := 0 // Variable to store a value for comparison
	f := false // Boolean variable to determine the output

	// Loop through each element
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i], &b[i]) // Read the values for arrays 'a' and 'b'
		if temp < a[i] { // Check if the current 'a' value is greater than the stored 'temp' value
			if q > b[i] { // Check if the stored 'q' value is greater than the current 'b' value
				f = true // Set 'f' to true if the condition is met
			}
			q = b[i] // Update 'q' with the current 'b' value
			temp = a[i] // Update 'temp' with the current 'a' value
		}
		if temp > a[i] { // Check if the current 'a' value is less than the stored 'temp' value
			if q < b[i] { // Check if the stored 'q' value is less than the current 'b' value
				f = true // Set 'f' to true if the condition is met
			}
			q = b[i] // Update 'q' with the current 'b' value
			temp = a[i] // Update 'temp' with the current 'a' value
		}
		if a[i] > w { // Check if the current 'a' value is greater than the stored 'w' value
			w = a[i] // Update 'w' with the current 'a' value
			if b[i] < e { // Check if the current 'b' value is less than the stored 'e' value
				f = true // Set 'f' to true if the condition is met
			}
			e = b[i] // Update 'e' with the current 'b' value
		}
		if a[i] < w { // Check if the current 'a' value is less than the stored 'w' value
			if b[i] > e { // Check if the current 'b' value is greater than the stored 'e' value
				f = true // Set 'f' to true if the condition is met
			}
		}
	}

	// Determine and print the output based on the value of 'f'
	if f {
		fmt.Println("Happy Alex") // Print "Happy Alex" if 'f' is true
	} else {
		fmt.Println("Poor Alex") // Print "Poor Alex" if 'f' is false
	}
}

// <END-OF-CODE>

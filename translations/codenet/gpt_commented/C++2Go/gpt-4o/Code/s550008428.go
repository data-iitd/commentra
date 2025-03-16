package main

import (
	"fmt"
)

func main() {
	var s int
	var x int
	d := 2 // Initialize depth

	fmt.Scan(&s) // Read an integer input from the user
	a := make(map[int]struct{}) // Create a map to store unique values of s
	a[s] = struct{}{} // Insert the initial value of s into the map

	// Start an infinite loop to process the value of s
	for {
		if s%2 == 0 { // Check if s is even
			x = s / 2 // If even, calculate the next value as half of s
		} else {
			x = 3*s + 1 // If odd, calculate the next value using the formula 3*s + 1
		}

		// Check if the new value x already exists in the map
		if _, exists := a[x]; exists {
			fmt.Println(d) // If it exists, print the depth and exit
			return
		}
		a[x] = struct{}{} // Insert the new value x into the map
		s = x // Update s to the new value x for the next iteration
		d++ // Increment the depth counter
	}

	// This line will never be reached due to the infinite loop
	fmt.Println(d) // Print the depth (not reached)

	return // Return to indicate successful completion of the program
}

// <END-OF-CODE>

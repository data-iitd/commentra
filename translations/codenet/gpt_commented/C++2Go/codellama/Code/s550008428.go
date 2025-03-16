package main

import (
	"fmt"
	"math"
)

func main() {
	var s, x, d int = 2, 2, 2 // Initialize variables: s for input, x for calculations, d for depth
	fmt.Scan(&s)               // Read an integer input from the user
	a := make(map[int]bool)    // Create a map to store unique values of s
	a[s] = true                // Insert the initial value of s into the map

	// Start an infinite loop to process the value of s
	for {
		// Check if s is even
		if s%2 == 0 {
			x = s / 2 // If even, calculate the next value as half of s
			// Check if the new value x already exists in the map
			if a[x] {
				fmt.Println(d) // If it exists, print the depth and exit
				return         // Return from the function
			}
			a[x] = true // Insert the new value x into the map
		} else {
			// If s is odd, calculate the next value using the formula 3*s + 1
			x = 3*s + 1
			// Check if the new value x already exists in the map
			if a[x] {
				fmt.Println(d) // If it exists, print the depth and exit
				return         // Return from the function
			}
			a[x] = true // Insert the new value x into the map
		}
		s = x // Update s to the new value x for the next iteration
		d++   // Increment the depth counter
	}

	// This line will never be reached due to the infinite loop
	fmt.Println(d) // Print the depth (not reached)
}


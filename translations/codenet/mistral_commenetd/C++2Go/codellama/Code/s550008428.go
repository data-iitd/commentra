
package main

import (
	"fmt"
	"math"
)

func main() {
	var s, x, d int = 2, 2, 2 // Initialize variables s, x, and d with initial values

	fmt.Scan(&s) // Read an integer value from the standard input and assign it to variable s
	a := make(map[int]bool) // Create an empty map named a
	a[s] = true // Add the value of s to the map a

	for { // Start an infinite loop
		if s%2 == 0 { // Check if s is even
			x = s / 2 // Calculate the half of s and assign it to x
			if a[x] { // Check if x is already in the map a
				fmt.Println(d) // If yes, print the value of d and exit the program
				return // Return from the function
			}
			a[x] = true // If not, add x to the map a and assign it to s for the next iteration
		} else { // If s is odd
			x = 3*s + 1 // Calculate 3s + 1 and assign it to x
			if a[x] { // Check if x is already in the map a
				fmt.Println(d) // If yes, print the value of d and exit the program
				return // Return from the function
			}
			a[x] = true // If not, add x to the map a and assign it to s for the next iteration
		}
		s = x // Update the value of s with the new value of x
		d++ // Increment the value of d for each iteration
	}

	fmt.Println(d) // Print the value of d if the loop terminates due to a condition other than finding a duplicate number in the map

	return // Return from the function
}


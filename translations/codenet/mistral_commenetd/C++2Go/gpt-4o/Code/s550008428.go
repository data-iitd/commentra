package main

import (
	"fmt"
)

func main() {
	var s, x, d int = 0, 0, 2 // Initialize variables s, x, and d with initial values

	fmt.Scan(&s) // Read an integer value from the standard input and assign it to variable s
	a := make(map[int]struct{}) // Create an empty set using a map
	a[s] = struct{}{} // Add the value of s to the set a

	for {
		if s%2 == 0 { // Check if s is even
			x = s / 2 // Calculate the half of s and assign it to x
			if _, exists := a[x]; exists { // Check if x is already in the set a
				fmt.Println(d) // If yes, print the value of d and exit the program
				return
			}
			a[x] = struct{}{} // If not, add x to the set a
		} else { // If s is odd
			x = 3*s + 1 // Calculate 3s + 1 and assign it to x
			if _, exists := a[x]; exists { // Check if x is already in the set a
				fmt.Println(d) // If yes, print the value of d and exit the program
				return
			}
			a[x] = struct{}{} // If not, add x to the set a
		}
		s = x // Update the value of s with the new value of x
		d++ // Increment the value of d for each iteration
	}

	// The following line is unreachable due to the infinite loop
	// fmt.Println(d) // Print the value of d if the loop terminates due to a condition other than finding a duplicate number in the set

	return // Exit the program
}

// <END-OF-CODE>

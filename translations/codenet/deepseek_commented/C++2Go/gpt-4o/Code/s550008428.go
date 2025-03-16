package main

import (
	"fmt"
)

func main() {
	var s, x, d int = 0, 0, 2
	fmt.Scan(&s) // Read the initial number from the user
	a := make(map[int]struct{}) // Create a set using a map
	a[s] = struct{}{} // Insert the initial number into the set

	for {
		if s%2 == 0 { // Check if the current number is even
			x = s / 2 // Halve the number
			if _, exists := a[x]; exists { // Check if the halved number has been encountered before
				fmt.Println(d) // Output the current step count and terminate the program
				return
			}
			a[x] = struct{}{} // Insert the halved number into the set
		} else { // The current number is odd
			x = 3*s + 1 // Triple the number and add one
			if _, exists := a[x]; exists { // Check if the new number has been encountered before
				fmt.Println(d) // Output the current step count and terminate the program
				return
			}
			a[x] = struct{}{} // Insert the new number into the set
		}
		s = x // Update the current number to the new number
		d++ // Increment the step count
	}

	// The following line will never be reached
	// fmt.Println(d)

}

// <END-OF-CODE>

package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the first integer from the input

	// Check if the input is 1, if so, print the only integer and exit the program
	if n == 1 {
		var singleInt int
		fmt.Scan(&singleInt)
		fmt.Println(singleInt) // Print the only integer
		return                 // Exit the program
	}

	// Initialize a slice to store the integers
	a := make([]int, n)

	// Read the rest of the integers and add them to the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Sort the slice in ascending order
	sort.Ints(a)

	// Check if the last integer in the slice is 0, if so, print 0 and exit the program
	if a[len(a)-1] == 0 {
		fmt.Println(0) // Print 0
		return         // Exit the program
	}

	// Initialize the answer variable
	var ans int

	// Use a loop to keep applying the function to the slice until it contains only one element
	for {
		if len(a) == 1 {
			ans = a[0] // Assign the only remaining integer to the answer variable
			break      // Exit the loop
		}
		a = func(a) // Apply the function to the slice and assign the result back to it
	}

	// Print the answer
	fmt.Println(ans)
}

// Define a function to apply the logic to the slice
func func(A []int) []int {
	a := A // Create a copy of the slice to modify it without affecting the original one
	min := 0

	// Iterate through the slice and apply the logic to each integer
	for i := 0; i < len(a); i++ {
		if a[i] == 0 { // If the current integer is 0, remove it and decrease the index of the for loop
			a = append(a[:i], a[i+1:]...) // Remove the element at index i
			i--                           // Decrement i to account for the removed element
		} else {
			if min != 0 { // If there is already a minimum value, apply the modulo operation and check if the result is 1
				a[i] = a[i] % min
				if a[i] == 1 { // If the result is 1, print 1 and exit the program
					fmt.Println(1)
					return nil // Exit the program
				}
			} else { // If there is no minimum value yet, assign the current integer as the minimum value
				min = a[i]
			}
		}
	}

	// Sort the slice in ascending order and return it
	sort.Ints(a)
	return a
}

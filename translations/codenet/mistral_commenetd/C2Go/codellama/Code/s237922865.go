package main

import "fmt"

func main() {
	// Declare and initialize variables
	var n int

	// Read an integer value from the user
	fmt.Print("Enter the number of integers: ")
	fmt.Scan(&n)

	cnt4, cnt2 := 0, 0 // Initialize counters for 4's and 2's multiples

	// Iterate through each integer input
	for i := 0; i < n; i++ {
		var wk int // Declare and initialize a variable to store the current integer input

		// Read an integer value from the user
		fmt.Print("Enter an integer: ")
		fmt.Scan(&wk)

		// Check if the current integer is a multiple of 4
		if wk%4 == 0 {
			cnt4++ // Increment the counter for 4's multiples
		} else if wk%2 == 0 {
			cnt2++ // Increment the counter for 2's multiples
		}
	}

	// Check the condition to determine the output
	if cnt4+cnt2/2 >= n/2 {
		fmt.Println("Yes") // Output "Yes" if the condition is true
	} else {
		fmt.Println("No") // Output "No" if the condition is false
	}

	// Main function ends here
}


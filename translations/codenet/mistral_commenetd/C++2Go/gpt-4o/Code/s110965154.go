package main

import (
	"fmt"
)

func sort(a_rvecIntValue []int) {
	// Iterate through each element in the slice starting from the second element
	for i := 1; i < len(a_rvecIntValue); i++ {
		iIntValue := a_rvecIntValue[i] // Get the value of the current element
		j := i - 1                      // Initialize a variable to store the index of the previous element
		for j >= 0 && a_rvecIntValue[j] > iIntValue { // While the previous element is greater than the current element
			a_rvecIntValue[j+1] = a_rvecIntValue[j] // Swap the previous and next elements
			j-- // Decrement the index of the previous element
		}
		a_rvecIntValue[j+1] = iIntValue // Place the current element at its correct position

		// Print the sorted slice after each insertion
		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Print(a_rvecIntValue[k]) // Print the value of the current element
			if k != len(a_rvecIntValue)-1 { // Check if we are not at the last element
				fmt.Print(" ") // Print a space if not
			}
		}
		fmt.Println() // Print a newline after each pass
	}
}

func main() {
	var iNum int // Initialize a variable to store the number of elements in the slice
	fmt.Scan(&iNum) // Read the number of elements from the standard input

	vecIntValue := make([]int, 0, iNum) // Create a slice to store the integers
	for iNum > 0 {
		var iIntValue int // Initialize a variable to store the next integer to be added to the slice
		fmt.Scan(&iIntValue) // Read the next integer from the standard input
		vecIntValue = append(vecIntValue, iIntValue) // Add the integer to the slice
		iNum-- // Decrement the counter
	}

	// Call the sorting function to sort the slice
	sort(vecIntValue)
}

// <END-OF-CODE>

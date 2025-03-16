/*
 * InsertionSort.go
 *
 *  Created on: 2014/07/25
 *      Author: WanWan1985
 */

package main

import (
	"fmt"
)

// Function prototype for the sorting function
func sort(a_rvecIntValue []int)

func main() {
	// Variable to hold the number of integers to be sorted
	var iNum int
	// Read the number of integers from standard input
	fmt.Scan(&iNum)

	// Vector to store the integers
	var vecIntValue []int

	// Loop to read integers from input and store them in the vector
	for iNum > 0 {
		var iIntValue int
		fmt.Scan(&iIntValue) // Read an integer
		vecIntValue = append(vecIntValue, iIntValue) // Add the integer to the vector
		iNum-- // Decrement the count of integers to read
	}

	// Call the sort function to sort the vector of integers
	sort(vecIntValue)
}

// Function to perform insertion sort on the vector of integers
func sort(a_rvecIntValue []int) {
	// Iterate through each element in the vector
	for i := 0; i < len(a_rvecIntValue); i++ {
		// Check if we are not at the first element
		if i != 0 {
			// Store the current element to be inserted
			iIntValue := a_rvecIntValue[i]
			j := i - 1 // Start comparing with the previous element

			// Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
			// to one position ahead of their current position
			for j >= 0 && a_rvecIntValue[j] > iIntValue {
				a_rvecIntValue[j+1] = a_rvecIntValue[j] // Shift element to the right
				j-- // Move to the previous element
			}
			// Place the current element at its correct position
			a_rvecIntValue[j+1] = iIntValue
		}

		// Print the current state of the sorted portion of the vector
		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Print(a_rvecIntValue[k]) // Output the element
			// Print a space between elements, but not after the last element
			if k != len(a_rvecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println() // New line after printing the current state
	}
}


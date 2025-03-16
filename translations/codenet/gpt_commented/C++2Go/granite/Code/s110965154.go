
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function prototype for the sorting function
func sort(a_rvecIntValue []int)

func main() {
	// Variable to hold the number of integers to be sorted
	var iNum int
	// Read the number of integers from standard input
	fmt.Fscanf(os.Stdin, "%d\n", &iNum)

	// Vector to store the integers
	vecIntValue := make([]int, iNum)

	// Loop to read integers from input and store them in the vector
	for i := 0; i < iNum; i++ {
		var iIntValue int
		fmt.Fscanf(os.Stdin, "%d\n", &iIntValue) // Read an integer
		vecIntValue[i] = iIntValue // Add the integer to the vector
	}

	// Call the sort function to sort the vector of integers
	sort(vecIntValue)

	// Print the sorted vector
	for i := 0; i < iNum; i++ {
		fmt.Printf("%d ", vecIntValue[i]) // Output the element
	}
	fmt.Println() // New line after printing the sorted vector
}

// Function to perform insertion sort on the vector of integers
func sort(a_rvecIntValue []int) {
	for i := 1; i < len(a_rvecIntValue); i++ {
		// Store the current element to be inserted
		iIntValue := a_rvecIntValue[i]
		j := i - 1

		// Move elements of a_rvecIntValue[0..i-1], that are greater than iIntValue,
		// to one position ahead of their current position
		for j >= 0 && a_rvecIntValue[j] > iIntValue {
			a_rvecIntValue[j+1] = a_rvecIntValue[j] // Shift element to the right
			j-- // Move to the previous element
		}
		// Place the current element at its correct position
		a_rvecIntValue[j+1] = iIntValue

		// Print the current state of the sorted portion of the vector
		for k := 0; k < len(a_rvecIntValue); k++ {
			fmt.Printf("%d ", a_rvecIntValue[k]) // Output the element
			// Print a space between elements, but not after the last element
			if k!= len(a_rvecIntValue)-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println() // New line after printing the current state
	}
}


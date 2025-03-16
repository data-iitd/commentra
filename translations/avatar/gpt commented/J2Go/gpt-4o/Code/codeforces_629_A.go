package main

import (
	"fmt"
)

func main() {
	// Create a variable to read the number of strings to be processed
	var num int
	fmt.Scan(&num)

	// Initialize counters for occurrences of 'C' and the total fine
	counter := 0
	fine := 0

	// Create a slice to store the input strings
	arr := make([]string, num)

	// Read 'num' strings from input and add them to the slice
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}

	// Calculate fines based on occurrences of 'C' in each column
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			// Count occurrences of 'C' in the current column
			if arr[k][i] == 'C' {
				counter++
			}
		}
		// Update the fine based on the number of 'C's found in this column
		fine += (counter * (counter - 1)) / 2
		// Reset counter for the next column
		counter = 0
	}

	// Calculate fines based on occurrences of 'C' in each row
	for i := 0; i < num; i++ {
		for k := 0; k < num; k++ {
			// Count occurrences of 'C' in the current row
			if arr[i][k] == 'C' {
				counter++
			}
		}
		// Update the fine based on the number of 'C's found in this row
		fine += (counter * (counter - 1)) / 2
		// Reset counter for the next row
		counter = 0
	}

	// Output the total fine calculated
	fmt.Println(fine)
}

// <END-OF-CODE>

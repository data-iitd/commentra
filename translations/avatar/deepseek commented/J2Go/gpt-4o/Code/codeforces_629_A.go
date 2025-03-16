package main

import (
	"fmt"
)

func main() {
	var num int
	fmt.Scan(&num) // Read the size of the grid
	counter := 0   // Counter for the number of 'C's
	fine := 0      // Fine amount to be calculated
	arr := make([]string, num) // Slice to store the grid rows

	// Read num strings representing the grid rows
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}

	// Calculate the fine for each column
	for i := 0; i < num; i++ {
		counter = 0 // Reset the counter for each column
		for k := 0; k < num; k++ {
			if arr[k][i] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2 // Calculate the fine for the column
	}

	// Calculate the fine for each row
	for i := 0; i < num; i++ {
		counter = 0 // Reset the counter for each row
		for k := 0; k < num; k++ {
			if arr[i][k] == 'C' {
				counter++
			}
		}
		fine += (counter * (counter - 1)) / 2 // Calculate the fine for the row
	}

	// Print the total fine
	fmt.Println(fine)
}

// <END-OF-CODE>

package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the first integer from the input as the size of the array

	arr := []int{} // Creating an empty slice to store the indices of the 1's in the input

	for i := 0; i < n; i++ { // Loop through the input to find the indices of the 1's
		var input int
		fmt.Scan(&input) // Read the next integer from input
		if input == 1 {
			arr = append(arr, i) // If the current input is 1, add its index to the slice
		}
	}

	if len(arr) == 0 { // Check if the slice is empty
		fmt.Println(0) // If it is, print 0 as the output
	} else {
		result := int64(1) // Initialize the result variable to 1

		for i := 1; i < len(arr); i++ { // Loop through the slice to calculate the result
			result *= int64(arr[i]) - int64(arr[i-1]) // Multiply the difference between two consecutive indices to the result
		}

		fmt.Println(result) // Print the result as the output
	}
}

// <END-OF-CODE>

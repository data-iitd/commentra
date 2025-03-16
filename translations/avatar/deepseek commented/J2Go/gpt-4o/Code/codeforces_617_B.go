package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Step 5: Read the number of elements.
	arr := []int{} // Step 6: Create a slice to store the indices of elements equal to 1.

	for i := 0; i < n; i++ { // Step 7: Read the elements and store their indices if they are equal to 1.
		var element int
		fmt.Scan(&element)
		if element == 1 {
			arr = append(arr, i)
		}
	}

	if len(arr) == 0 { // Step 8: Check if the slice is empty.
		fmt.Println(0) // If the slice is empty, print 0.
	} else {
		result := int64(1) // Initialize the result variable to 1.
		for i := 1; i < len(arr); i++ { // Step 9: Calculate the product of differences between consecutive indices.
			result *= int64(arr[i] - arr[i-1])
		}
		fmt.Println(result) // Print the result.
	}
}

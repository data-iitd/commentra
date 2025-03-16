package main

import (
	"fmt"
	"sort"
)

func main() {
	// Take the first line of input which are two integers 'num' and 'k'
	var num, k int
	fmt.Scan(&num, &k)

	// Comment: Initialize 'num' and 'k' with the values from user input

	// Take the second line of input which is a list 'arr' of integers
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}

	// Comment: Initialize an empty list 'arr' to store the input integers

	// Create an empty map 'different' to store unique integers
	different := make(map[int]struct{})

	// Comment: Initialize an empty map 'different' to store unique integers

	// Sort the list 'arr' in ascending order
	sort.Ints(arr)

	// Comment: Sort the list 'arr' in ascending order for easier comparison

	// Initialize a variable to track the maximum length of 'different'
	temp := 0

	// Iterate through each integer 'x' in the sorted list 'arr'
	for _, x := range arr {
		// Check if 'x' is not divisible by 'k' or if its quotient is not already in 'different'
		if x%k != 0 || _, exists := different[x/k]; !exists {
			// If the condition is true, add 'x' to the map 'different'
			different[x] = struct{}{}

			// Comment: If 'x' is not divisible by 'k' or its quotient is not already in 'different', add it to 'different'
		}

		// Update the maximum length of 'different' seen so far
		temp = max(temp, len(different))
	}

	// Comment: After the loop, 'temp' stores the maximum length of 'different' seen during the iteration

	// Print the maximum length of 'different'
	fmt.Println(temp)

	// Comment: Finally, print the maximum length of 'different'
}

// max function to return the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>

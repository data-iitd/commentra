package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read two integers from input: num (number of elements) and k (the divisor)
	var num, k int
	fmt.Scan(&num, &k)

	// Read the array of integers from input
	arr := make([]int, num)
	for i := 0; i < num; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize a map to keep track of unique elements that meet the criteria
	different := make(map[int]struct{})

	// Initialize a variable to keep track of the maximum size of the 'different' set
	temp := 0

	// Sort the array to process elements in ascending order
	sort.Ints(arr)

	// Iterate through each element in the sorted array
	for _, x := range arr {
		// Check if the element is not divisible by k or if its quotient is not already in the 'different' set
		if x%k != 0 || _, exists := different[x/k]; !exists {
			// Add the element to the 'different' set since it meets the criteria
			different[x] = struct{}{}
		}

		// Update the maximum size of the 'different' set if the current size is larger
		temp = max(len(different), temp)
	}

	// Print the maximum size of the 'different' set found
	fmt.Println(temp)
}

// Helper function to get the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"sort"
)

func main() {
	// Create a variable to read the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Read the value of k
	var k int64
	fmt.Scan(&k)

	// Initialize a slice to hold the input numbers
	arr := make([]int64, n)

	// Create a map to store unique elements that meet the criteria
	set := make(map[int64]struct{})

	// Read n long integers into the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Sort the slice to facilitate the processing of elements
	sort.Slice(arr, func(i, j int) bool {
		return arr[i] < arr[j]
	})

	// Initialize a counter to keep track of valid elements
	count := 0

	// Iterate through the sorted slice to apply the conditions
	for i := 0; i < n; i++ {
		// Check if the current element is not divisible by k
		if arr[i]%k != 0 {
			count++ // Increment count for valid element
			set[arr[i]] = struct{}{} // Add the element to the set
		} else if _, exists := set[arr[i]/k]; !exists { // Check if the current element is divisible by k
			count++ // Increment count for valid element
			set[arr[i]] = struct{}{} // Add the element to the set
		}
	}

	// Output the final count of valid elements
	fmt.Println(count)
}

// <END-OF-CODE>

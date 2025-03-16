package main

import (
	"fmt"
)

// Function to perform binary search on a sorted list
func binarySearch(key int, ans [][]int) int {
	// Initialize two pointers, 'bad' and 'good' to represent the left and right indices of the subarray
	bad, good := -1, len(ans)

	// Continue searching until the subarray is not divided anymore
	for good-bad > 1 {
		// Calculate the middle index of the subarray
		mid := (bad + good) / 2

		// Check if the middle element is less than the key
		if ans[mid][len(ans[mid])-1] < key {
			// If yes, update 'good' to be the new left index
			good = mid
		} else {
			// If no, update 'bad' to be the new right index
			bad = mid
		}
	}

	// Return the index where the key is located
	return good
}

func main() {
	// Read the number of elements in the list
	var N int
	fmt.Scan(&N)

	// Initialize an empty list to store the elements
	ans := [][]int{}

	// Read each element and perform binary search to find its position in the list
	for i := 0; i < N; i++ {
		// Read an element
		var A int
		fmt.Scan(&A)

		// Perform binary search to find the index of the element
		idx := binarySearch(A, ans)

		// If the element is not already in the list, append it to the list
		if idx == len(ans) {
			ans = append(ans, []int{A})
		} else {
			// If the element is already in the list, append it to the existing list
			ans[idx] = append(ans[idx], A)
		}
	}

	// Print the number of unique elements in the list
	fmt.Println(len(ans))
}

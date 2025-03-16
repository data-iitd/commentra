package main

import "fmt"

func main() {
	// Read the number of elements
	var N int
	fmt.Scanf("%d", &N)

	// Initialize an empty list to hold the subsequences
	ans := make([][]int, 0)

	// Iterate over the range of N to read each element
	for i := 0; i < N; i++ {
		var A int
		fmt.Scanf("%d", &A)  // Read the current element
		idx := binarySearch(A, ans)  // Find the position to insert the element

		// If the index is equal to the length of ans, it means A is greater than all elements
		if idx == len(ans) {
			ans = append(ans, []int{A})  // Start a new subsequence with A
		} else {
			// Otherwise, append A to the existing subsequence at index idx
			ans[idx] = append(ans[idx], A)
		}
	}

	// Print the number of subsequences formed
	fmt.Println(len(ans))
}

// binarySearch returns the index where the key should be inserted
func binarySearch(key int, arr [][]int) int {
	// Initialize the boundaries for binary search
	bad, good := -1, len(arr)

	// Continue searching while there is more than one element in the range
	for good-bad > 1 {
		mid := (bad + good) / 2  // Calculate the middle index
		// If the last element of the mid list is less than the key, move the good boundary
		if arr[mid][len(arr[mid])-1] < key {
			good = mid
		} else {
			// Otherwise, move the bad boundary
			bad = mid
		}
	}

	// Return the index where the key should be inserted
	return good
}


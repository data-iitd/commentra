package main

import (
	"fmt"
	"sort"
)

func main() {
	// Read the number of integers to be processed
	var N int
	fmt.Scan(&N)

	// Initialize a slice to store the integers
	L := make([]int, N)

	// Read N integers from input and add them to the slice
	for i := 0; i < N; i++ {
		fmt.Scan(&L[i])
	}

	// Sort the slice of integers in ascending order
	sort.Ints(L)

	// Initialize a counter to keep track of valid pairs
	count := 0

	// Iterate through each pair of integers in the sorted slice
	for i := 0; i < N; i++ {
		for j := i + 1; j < N; j++ {
			// Get the current pair of integers
			a := L[i]
			b := L[j]

			// Find the number of integers that can form a valid triplet with a and b
			res := find(L, j+1, a+b)

			// Increment the count by the number of valid triplets found
			count += res
		}
	}

	// Output the total count of valid triplets
	fmt.Println(count)
}

// Method to find the count of integers in the slice that can form a valid triplet
func find(li []int, from int, target int) int {
	low := from
	upp := len(li) - 1

	// Base cases for the search
	if upp-low < 0 {
		return 0
	} else if li[from] >= target {
		return 0
	} else if li[upp] < target {
		return upp - low + 1
	}

	// Perform binary search to find the count of valid integers
	for upp-low > 1 {
		mid := (low + upp) / 2
		if li[mid] >= target {
			upp = mid
		} else {
			low = mid
		}
	}

	// Return the count of valid integers found
	return low - from + 1
}

// <END-OF-CODE>

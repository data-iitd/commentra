package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Reading the number of elements in the array from the user

	// Allocating memory for the array and initializing it with user input
	ans := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ans[i]) // Reading each element of the array one by one
	}

	// Sorting the array in ascending order
	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	// Initializing a variable to keep track of the count
	count := ans[n-1] // The last element of the sorted array is the maximum element

	// Iterating through the array from the second last element to the first
	for i := n - 2; i >= 0; i-- {
		// If the current element is less than the next element, add it to the count
		if ans[i] < ans[i+1] {
			count += ans[i]
		} else { // If the current element is greater than or equal to the next element
			// Decrement the current element until it becomes less than the next element
			for ans[i] >= ans[i+1] {
				ans[i]--
			}

			// If the current element is still greater than or equal to the next element, add it to the count
			if ans[i] > 0 {
				count += ans[i]
			}
		}
	}

	// Printing the final count
	fmt.Println(count)
}

// <END-OF-CODE>

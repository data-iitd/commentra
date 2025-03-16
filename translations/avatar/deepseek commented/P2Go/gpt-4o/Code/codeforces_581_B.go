package main

import (
	"fmt"
)

func main() {
	// Step 1: Take the number of elements in the array as input
	var n int
	fmt.Scan(&n)

	// Step 2: Take a space-separated string of integers as input, convert them to a slice of integers
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Step 3: Initialize a slice `ans` of zeros with the same length as the input array
	ans := make([]int, n)

	// Step 4: Initialize `mx` to the last element of the array `arr`
	mx := arr[n-1]

	// Step 5: Iterate from the second last element to the first element of the array `arr` in reverse order
	for i := n - 2; i >= 0; i-- {
		// Step 6: Calculate the value `max(0, mx - arr[i] + 1)` and assign it to the corresponding position in the `ans` slice
		if mx-arr[i]+1 > 0 {
			ans[i] = mx - arr[i] + 1
		} else {
			ans[i] = 0
		}

		// Step 7: If the current element is greater than `mx`, update `mx` with the current element
		if arr[i] > mx {
			mx = arr[i]
		}
	}

	// Step 8: Print the elements of the `ans` slice
	for _, value := range ans {
		fmt.Print(value, " ")
	}
	fmt.Println()
}

// <END-OF-CODE>

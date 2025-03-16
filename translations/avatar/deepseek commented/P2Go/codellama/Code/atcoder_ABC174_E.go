package main

import (
	"fmt"
	"math"
)

func check(lis []int, k int, mid int) bool {
	// This function checks if it's possible to distribute the elements of lis
	// such that each element is at most mid and the total number of operations
	// does not exceed k.
	for _, i := range lis {
		if i%mid == 0 { // If i is divisible by mid, increment k by 1.
			k++
		}
		k -= i / mid // Subtract the number of elements that can be handled by mid from k.
	}
	return k >= 0 // Return True if k is non-negative, else False.
}

func main() {
	// Read the number of elements (n) and the initial value of k from input.
	var n, k int
	fmt.Scan(&n, &k)

	// Read the list of integers from input.
	lis := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lis[i])
	}

	// Initialize the search range with 1 and the maximum value in the list.
	a, b := 1, lis[0]
	for i := 1; i < n; i++ {
		if lis[i] > b {
			b = lis[i]
		}
	}

	// Initialize the answer with the maximum value in the list.
	ans := b

	// Perform a binary search to find the maximum value of mid that satisfies the condition.
	for a <= b {
		mid := (a + b) / 2 // Calculate the middle value of the current search range.
		if check(lis, k, mid) { // Check if the current mid value is valid.
			ans = mid // Update the answer to the current mid value.
			b = mid - 1 // Adjust the upper bound of the search range.
		} else {
			a = mid + 1 // Adjust the lower bound of the search range.
		}
	}

	// Print the result, which is the maximum value of mid that satisfies the condition.
	fmt.Println(ans)
}


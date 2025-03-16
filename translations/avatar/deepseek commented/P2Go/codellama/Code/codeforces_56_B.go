
package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i], _ = strconv.Atoi(strings.Split(fmt.Scanln(), " ")[i])
	}

	// Initialize variables to track the minimum and maximum indices where the condition is true
	mn, mx := N+1, -1

	// Iterate over the range of N to find the indices where the condition is true
	for i := 0; i < N; i++ {
		if i+1 != A[i] {
			mn = min(mn, i) // Update mn if a smaller index is found
			mx = max(mx, i) // Update mx if a larger index is found
		}
	}

	// Check if no indices satisfy the condition
	if mx == -1 {
		fmt.Println("0 0") // Print '0 0' if no indices satisfy the condition
	} else {
		// Reverse the sublist from index mn to mx + 1 and update A
		A = A[:mn] + A[mn:(mx+1)][::-1] + A[(mx+1):]

		// Check if the list A is sorted
		if sorted(A) == A {
			fmt.Println(mn+1, mx+1) // Print the indices if A is sorted
		} else {
			fmt.Println("0 0") // Print '0 0' if A is not sorted
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func sorted(A []int) []int {
	for i := 0; i < len(A)-1; i++ {
		if A[i] > A[i+1] {
			return A
		}
	}
	return A
}

// 
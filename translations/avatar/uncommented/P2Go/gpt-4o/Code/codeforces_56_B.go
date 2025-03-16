package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	mn, mx := N+1, -1
	for i := 0; i < N; i++ {
		if i+1 != A[i] {
			mn = min(mn, i)
			mx = max(mx, i)
		}
	}

	if mx == -1 {
		fmt.Println("0 0")
	} else {
		// Create a new slice for the modified array
		newA := make([]int, 0, N)
		newA = append(newA, A[:mn]...) // Elements before mn
		for j := mx; j >= mn; j-- {    // Reversed elements from mn to mx
			newA = append(newA, A[j])
		}
		newA = append(newA, A[mx+1:]...) // Elements after mx

		// Check if the new array is sorted
		if sort.IntsAreSorted(newA) {
			fmt.Println(mn+1, mx+1)
		} else {
			fmt.Println("0 0")
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

// <END-OF-CODE>

package main

import (
	"fmt"
)

func binarySearch(key int, ans [][]int) int {
	bad, good := -1, len(ans)

	for good-bad > 1 {
		mid := (bad + good) / 2
		if ans[mid][len(ans[mid])-1] < key {
			good = mid
		} else {
			bad = mid
		}
	}

	return good
}

func main() {
	var N int
	fmt.Scan(&N)

	// Initialize the list of lists
	ans := [][]int{}

	// Read each element and insert it into the appropriate position
	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		idx := binarySearch(A, ans)
		if idx == len(ans) {
			// If the key should be inserted at the end, append a new sublist
			ans = append(ans, []int{A})
		} else {
			// Otherwise, insert the key into the appropriate sublist
			ans[idx] = append(ans[idx], A)
		}
	}

	// Print the number of unique elements
	fmt.Println(len(ans))
}

// <END-OF-CODE>

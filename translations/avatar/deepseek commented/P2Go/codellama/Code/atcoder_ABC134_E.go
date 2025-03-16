
package main

import "fmt"

func binarySearch(key int, ans [][]int) int {
	// Initialize bad and good indices for binary search
	bad, good := -1, len(ans)

	// Perform binary search to find the correct position
	for good-bad > 1 {
		mid := (bad + good) / 2
		if ans[mid][len(ans[mid])-1] < key {
			good = mid
		} else {
			bad = mid
		}
	}

	// Return the index where the key should be inserted
	return good
}

func main() {
	// Read the number of elements
	var N int
	fmt.Scan(&N)

	// Initialize the list of lists
	ans := make([][]int, 0)

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


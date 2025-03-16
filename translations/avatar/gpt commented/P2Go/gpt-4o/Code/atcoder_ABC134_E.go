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

	ans := [][]int{}

	for i := 0; i < N; i++ {
		var A int
		fmt.Scan(&A)
		idx := binarySearch(A, ans)

		if idx == len(ans) {
			ans = append(ans, []int{A}) // Start a new subsequence with A
		} else {
			ans[idx] = append(ans[idx], A) // Append A to the existing subsequence at index idx
		}
	}

	fmt.Println(len(ans)) // Print the number of subsequences formed
}

// <END-OF-CODE>

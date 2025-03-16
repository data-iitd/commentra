package main

import (
	"fmt"
	"sort"
)

const SIZE = int(1e5*2) + 13

func main() {
	// Declare a count array initialized to zero with a size of SIZE
	cnt := make([]int, SIZE)

	// Read the number of elements (n) and the number of largest counts to keep (k)
	var n, k int
	fmt.Scan(&n, &k)

	// Read n integers and count their occurrences
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		// Increment the count for the number x
		cnt[x]++
	}

	// Declare a slice to hold the counts of each number
	var a []int

	// Transfer the counts of numbers that appeared at least once to slice a
	for i := 0; i < len(cnt); i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i]) // Add the count to slice a
		}
	}

	// Initialize the answer variable to accumulate the result
	ans := 0
	// Sort the counts in ascending order
	sort.Ints(a)

	// Calculate the number of counts to exclude (m) based on k
	m := len(a) - k
	// Sum the counts of the smallest m elements
	for i := 0; i < m; i++ {
		ans += a[i] // Add the count to the answer
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"sort"
)

const SIZE = int(1e5*2) + 13 // Define the size of the count array

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the number of elements and the threshold k

	cnt := make([]int, SIZE) // Slice to count occurrences of each integer

	// Count occurrences of each integer
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x]++
	}

	// Filter non-zero counts and store them in slice a
	var a []int
	for i := 0; i < len(cnt); i++ {
		if cnt[i] > 0 {
			a = append(a, cnt[i])
		}
	}

	// Sort the slice a in ascending order
	sort.Ints(a)

	// Calculate the sum of the smallest k counts in slice a
	ans := 0
	m := len(a) - k
	for i := 0; i < m; i++ {
		ans += a[i]
	}

	// Output the result
	fmt.Println(ans)
}

// <END-OF-CODE>

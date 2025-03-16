package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements
	const N = 1e5 + 5 // Define a constant N for array size
	cnt := make([]int64, 21) // Initialize a slice to count occurrences of each value shifted by 10

	// Count the occurrences of each value shifted by 10
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x) // Read each element
		cnt[x+10]++ // Increment the count for the shifted value
	}

	res := int64(0) // Initialize result variable

	// Calculate the number of pairs that sum up to 20
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i]
	}

	// Special case for pairs where both elements are the same (i.e., i = 10)
	res += (cnt[10] * (cnt[10] - 1)) / 2

	// Output the result
	fmt.Println(res)
}

// <END-OF-CODE>

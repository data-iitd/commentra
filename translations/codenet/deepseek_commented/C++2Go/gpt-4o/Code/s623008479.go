package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the values of n and k from the input
	l := make([]int, n) // Declare a slice of size n
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i]) // Read the elements of the slice l
	}

	sort.Ints(l) // Sort the slice l in ascending order

	ans := 0 // Initialize ans to 0
	for i := 0; i < k; i++ {
		ans += l[n-1-i] // Sum the last k elements of the sorted slice
	}
	fmt.Println(ans) // Print the result
}

// <END-OF-CODE>

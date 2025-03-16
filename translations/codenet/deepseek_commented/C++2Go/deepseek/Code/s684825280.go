package main

import (
	"fmt"
	"sort"
)

const SIZE = (1e5 * 2) + 13 // Define the size of the count array

var a []int // Slice to store non-zero counts
var cnt [SIZE]int // Array to count occurrences of each integer

func main() {
	var n, k int
	fmt.Scan(&n, &k) // Read the number of elements and the threshold k
	
	// Count occurrences of each integer
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		cnt[x]++
	}
	
	// Filter non-zero counts and store them in slice a
	for i := 0; i < SIZE; i++ {
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


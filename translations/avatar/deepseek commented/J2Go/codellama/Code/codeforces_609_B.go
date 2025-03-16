
package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	var arr []int
	var gen []int

	// Read the first integer n from input
	fmt.Scan(&n)

	// Read the second integer m from input
	fmt.Scan(&m)

	// Declare and initialize an array to store n integers
	arr = make([]int, n)

	// Declare and initialize an array to count occurrences of integers
	gen = make([]int, 11)

	// Read n integers from input and store them in arr, and count their occurrences in gen
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
		gen[arr[i]]++
	}

	var ans int64

	// Calculate the number of pairs (i, k) where i ≠ k and gen[i] and gen[k] are non-zero
	for i := 1; i <= m; i++ {
		for k := 1; k <= m; k++ {
			if i != k {
				ans += int64(gen[i]) * int64(gen[k])
			}
		}
	}

	// Print the result, which is half of the calculated pairs
	fmt.Println(ans / 2)
}


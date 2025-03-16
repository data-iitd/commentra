package main

import (
	"fmt"
	"sort"
)

func main() {
	// Step 1: Read the input value `n` which represents the number of elements to process.
	var n int
	fmt.Scan(&n)

	// Step 2: Read the array of size `3 * n` from the standard input.
	array := make([]int, 3*n)
	for i := 0; i < len(array); i++ {
		fmt.Scan(&array[i])
	}

	// Step 3: Sort the array in ascending order.
	sort.Ints(array)

	// Step 4: Initialize a variable `head` to point to the second last element of the array.
	head := len(array) - 2

	// Step 5: Initialize a variable `res` to store the result.
	var res int64 = 0

	// Step 6: Iterate `n` times, in each iteration:
	// - Add the value at the `head` position to `res`.
	// - Decrement `head` by 2.
	for i := 0; i < n; i++ {
		res += int64(array[head])
		head -= 2
	}

	// Step 7: Print the result `res`.
	fmt.Println(res)
}

// <END-OF-CODE>

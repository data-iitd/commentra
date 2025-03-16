package main

import (
	"fmt"
)

func main() {
	// Create a variable to read input from the console
	var n int
	// Read the number of integers to process
	fmt.Scan(&n)

	// Initialize a slice to count occurrences of integers in the range [-10, 10]
	cnt := make([]int64, 21) // Slice size is 21 to accommodate indices from 0 to 20

	// Loop to read n integers and count their occurrences
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		// Increment the count for the input integer adjusted by +10 to handle negative values
		cnt[num+10]++
	}

	// Variable to store the final result
	var res int64 = 0

	// Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
	for i := 0; i < 10; i++ {
		// Multiply the counts of i and (20 - i) and add to the result
		res += cnt[i] * cnt[20-i]
	}

	// Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
	res += (cnt[10] * (cnt[10] - 1)) / 2

	// Output the final result
	fmt.Println(res)
}

// <END-OF-CODE>

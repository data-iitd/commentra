package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of test cases from the console

	// Define the maximum size of the array to avoid array out of bounds exception
	const N = 100005

	// Initialize a slice to store the count of each number
	cnt := make([]int64, 21)

	// Read the numbers one by one and update the count slice accordingly
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num) // Read the next number
		cnt[num+10]++   // Increment the count of the number
	}

	// Calculate the result using the given formula
	var res int64 = 0
	for i := 0; i < 10; i++ {
		res += cnt[i] * cnt[20-i] // Calculate the sum of products of pairs of numbers with absolute difference i
	}
	res += (cnt[10] * (cnt[10] - 1)) / 2 // Calculate the sum of squares of numbers equal to 10 and add half of it

	// Print the result to the console
	fmt.Println(res)
}

// <END-OF-CODE>

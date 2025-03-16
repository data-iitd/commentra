package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of elements in the list
	l := make([]int, n) // Initialize a slice to store the elements

	// Read n elements and append them to the slice l
	for i := 0; i < n; i++ {
		fmt.Scan(&l[i])
	}

	ans := n - 1 // Initialize ans to n - 1, which will store the final answer
	last := 0    // Initialize last to 0, used to track the last element in the list

	// Iterate over each element in the slice l
	for _, i := range l {
		ans += int(math.Abs(float64(last-i))) + 1 // Update ans based on the current element and last element
		last = i // Update last to the current element
	}

	fmt.Println(ans) // Print the final answer
}

// <END-OF-CODE>

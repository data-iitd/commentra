package main

import (
	"fmt"
	"math"
)

func main() {
	// Ask the user for the number of elements in the list
	var n int
	fmt.Scan(&n)

	// Create a slice to hold the elements
	r := make([]int, n)

	// Ask the user to input the elements of the list separated by spaces
	for i := 0; i < n; i++ {
		fmt.Scan(&r[i])
	}

	// Initialize a variable to store the answer
	ans := math.Abs(float64(r[0]))

	// Use a for loop to calculate the sum of the absolute differences between consecutive elements
	for i := 1; i < n; i++ {
		ans += math.Abs(float64(r[i] - r[i-1]))
	}

	// Print the final answer
	fmt.Println(int(ans))
}

// <END-OF-CODE>

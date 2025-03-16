package main

import (
	"fmt"
)

func main() {
	// Create a Scanner object to read input from the console
	var n int
	fmt.Scan(&n)
	
	// Initialize an array to hold the input integers
	arr := make([]int, n)
	
	// Populate the array with integers from user input
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}
	
	// Initialize the answer with the first element of the array plus one
	ans := arr[0] + 1
	
	// Calculate the total distance based on the differences between consecutive elements
	for i := 1; i < n; i++ {
		// Add the absolute difference between the current and previous element, plus 2
		ans += abs(arr[i] - arr[i - 1]) + 2
	}
	
	// Output the final calculated answer
	fmt.Println(ans)
}

// Helper function to calculate the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}


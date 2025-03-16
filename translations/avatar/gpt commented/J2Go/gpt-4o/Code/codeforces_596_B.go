package main

import (
	"fmt"
	"math"
)

func main() {
	// Reading the number of elements in the array
	var n int
	fmt.Scan(&n)

	// Initializing a slice to hold the input values
	arr := make([]int64, n)

	// Loop to read 'n' integers from the user and store them in the slice
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize the answer with the absolute value of the first element
	answer := int64(math.Abs(float64(arr[0])))

	// Loop to calculate the sum of absolute differences between consecutive elements
	for i := 1; i < n; i++ {
		answer += int64(math.Abs(float64(arr[i] - arr[i-1])))
	}

	// Output the final calculated answer
	fmt.Println(answer)
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"math"
)

func main() {
	// Create a variable to read the first integer `n`
	var n int
	fmt.Scan(&n)

	// Create a new slice `arr` of size `n`
	arr := make([]int64, n)

	// Use a for loop to read `n` integers and assign them to the corresponding elements of the slice `arr`
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize the variable `answer` with the absolute value of the first element of the slice `arr`
	answer := int64(math.Abs(float64(arr[0])))

	// Use a for loop to iterate over the remaining elements of the slice `arr`
	for i := 1; i < n; i++ {
		answer += int64(math.Abs(float64(arr[i] - arr[i-1])))
	}

	// Print the value of the variable `answer`
	fmt.Println(answer)
}

// <END-OF-CODE>

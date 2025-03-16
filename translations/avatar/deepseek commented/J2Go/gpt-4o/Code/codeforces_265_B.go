package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the size of the array
	arr := make([]int, n) // Initialize the array of size n

	// Read n integers into the array
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Initialize ans with the value of the first element plus 1
	ans := arr[0] + 1

	// Iterate through the array and update ans
	for i := 1; i < n; i++ {
		ans += int(math.Abs(float64(arr[i] - arr[i-1]))) + 2
	}

	// Print the final value of ans
	fmt.Println(ans)
}

// <END-OF-CODE>

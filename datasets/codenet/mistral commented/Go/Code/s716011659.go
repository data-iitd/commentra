
package main

import (
	"fmt"
	"math"
)

const inf float64 = 1e12 // Constants should be defined with clear names and values

func main() {
	// Initialize variables and read input
	var n int
	fmt.Scan(&n)

	arrA := make([]int, n) // Create an array of size n to store input
	for i := 0; i < n; i++ {
		fmt.Scan(&arrA[i]) // Read each element of the array
	}

	cumSumA := make([]int, n+1) // Create an array of size n+1 to store cumulative sum
	cumSumA[0] = 0            // Initialize the first element of cumulative sum array
	for i, a := range arrA { // Iterate through the array and calculate cumulative sum
		cumSumA[i+1] = cumSumA[i] + a
	}

	// Initialize variable to store the answer
	ans := inf // Initialize with a large value

	// Iterate through the array to find the answer
	for i := 1; i < n; i++ {
		temp := float64(cumSumA[n]) - float64(cumSumA[i])*2 // Calculate the difference
		if math.Abs(temp) < ans { // If the difference is smaller than the current answer
			ans = temp // Update the answer
		}
	}

	// Print the answer
	fmt.Println(int(ans))

	// End of the code
}
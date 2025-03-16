package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // Reading N and K from input
	lst := make([]int, N) // Create a slice to store the integers
	for i := 0; i < N; i++ {
		fmt.Scan(&lst[i]) // Reading the list of integers
	}

	lstP := []int{} // Slice to store positive numbers
	lstM := []int{} // Slice to store negative numbers

	// Separating positive and negative numbers
	for i := 0; i < N; i++ {
		if lst[i] == 0 {
			K-- // Decrement K if the number is 0
		}
		if lst[i] > 0 {
			lstP = append(lstP, lst[i]) // Add positive numbers to lstP
		} else if lst[i] < 0 {
			lstM = append(lstM, lst[i]) // Add negative numbers to lstM
		}
	}

	// Initialization of pointers and variables
	lastX := len(lstP) // Last index of lstP
	lastY := len(lstM) // Last index of lstM

	// Function to check the minimum possible value
	check := func(k int) int {
		ans := math.MaxInt64 // Initialize answer with a large number
		for j := 0; j <= k; j++ {
			if j > lastX || k-j > lastY { // Check if indices are out of bounds
				continue
			}
			var p, m int
			if j == 0 {
				p = 0 // If no positive number is chosen, p is 0
			} else {
				p = lstP[j-1] // Get the (j-1)th positive number
			}
			if k-j == 0 {
				m = 0 // If no negative number is chosen, m is 0
			} else {
				m = lstM[lastY-(k-j)] // Get the (lastY - (k - j))th negative number
			}
			ans = min(ans, 2*p+abs(m), p+2*abs(m)) // Calculate the minimum value
		}
		return ans
	}

	// Output the result of the check function with K as the argument
	fmt.Println(check(K))
}

// Helper function to calculate absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// Helper function to find minimum of multiple values
func min(values ...int) int {
	minVal := values[0]
	for _, v := range values {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

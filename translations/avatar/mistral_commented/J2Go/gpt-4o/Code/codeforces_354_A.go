package main

import (
	"fmt"
	"math"
)

func main() {
	var N, L, R, QL, QR int
	fmt.Scan(&N, &L, &R, &QL, &QR) // Reading inputs

	W := make([]int, N)           // Creating an integer slice W of size N
	sum := make([]int, N+1)      // Creating an integer slice sum of size N+1

	for n := 0; n < N; n++ {     // Iterating through each element in the slice W
		fmt.Scan(&W[n])           // Reading the integer value of each element in the slice W
		sum[n+1] = sum[n] + W[n]  // Calculating the sum of all elements from 0 to n+1
	}

	min := math.MaxInt64         // Initializing the minimum value to be the maximum int value

	for firstR := 0; firstR <= N; firstR++ { // Iterating through all possible starting indices for the right segment
		lCount := firstR                          // The length of the left segment
		rCount := N - lCount                      // The length of the right segment

		cand := sum[lCount]*L + (sum[N] - sum[lCount])*R // Calculating the candidate value

		llCount := max(0, lCount-rCount-1) // Calculating the length of the overlapping part between the left and right segments
		rrCount := max(0, rCount-lCount-1) // Calculating the length of the overlapping part between the right and left segments

		cand += llCount * QL // Adding the contribution of the left overlapping part
		cand += rrCount * QR // Adding the contribution of the right overlapping part

		min = minInt(cand, min) // Updating the minimum value if the current candidate value is smaller
	}

	fmt.Println(min) // Printing the minimum value as the output
}

// Helper function to find the maximum of two integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// Helper function to find the minimum of two integers
func minInt(a, b int) int {
	if a < b {
		return a
	}
	return b
}

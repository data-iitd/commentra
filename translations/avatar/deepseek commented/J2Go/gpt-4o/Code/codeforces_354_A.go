package main

import (
	"fmt"
	"math"
)

func main() {
	var N, L, R, QL, QR int
	fmt.Scan(&N, &L, &R, &QL, &QR) // Reading the inputs

	W := make([]int, N) // Slice to store the weights of items
	sum := make([]int, N+1) // Slice to store cumulative sums of weights

	// Reading the weights and calculating cumulative sums
	for n := 0; n < N; n++ {
		fmt.Scan(&W[n])
		sum[n+1] = sum[n] + W[n]
	}

	// Initializing the minimum cost to a very large value
	min := math.MaxInt64

	// Iterating over possible positions for the rightmost item
	for firstR := 0; firstR <= N; firstR++ {
		lCount := firstR // Number of items on the left
		rCount := N - lCount // Number of items on the right

		// Calculating the cost for the current position of the rightmost item
		cand := int64(sum[lCount])*int64(L) + int64(sum[N]-sum[lCount])*int64(R)

		// Calculating the additional costs for unbalanced counts
		llCount := int64(0)
		if lCount > rCount+1 {
			llCount = int64(lCount - rCount - 1)
		}
		rrCount := int64(0)
		if rCount > lCount+1 {
			rrCount = int64(rCount - lCount - 1)
		}
		cand += llCount * int64(QL)
		cand += rrCount * int64(QR)

		// Updating the minimum cost found so far
		if cand < min {
			min = cand
		}
	}

	// Printing the minimum cost
	fmt.Println(min)
}

// <END-OF-CODE>

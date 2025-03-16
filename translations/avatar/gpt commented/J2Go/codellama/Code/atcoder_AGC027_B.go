package main

import (
	"fmt"
	"math"
)

func main() {
	// Initialize a Scanner to read input from the console
	sc := make([]int, 0)

	// Read the number of elements N and the multiplier X
	N := sc[0]
	X := sc[1]

	// Initialize an array to store the elements and a prefix sum array
	x := make([]int, N)
	xsum := make([]int, N + 1)

	// Read the elements into the array and compute the prefix sums
	for i := 0; i < N; i++ {
		x[i] = sc[i + 2]
		xsum[i + 1] = xsum[i] + x[i]
	}

	// Initialize the answer with the cost of processing all elements with the base cost
	ans := X * N + 5 * xsum[N]

	// Iterate through possible splits of the array
	for i := 1; i < N; i++ {
		// Calculate the cost for the current split
		cost := X * i + 5 * (xsum[N] - xsum[N-i])

		// Incrementally add costs based on the current split
		for j := 5, k := N - i; k >= 0; j += 2, k -= i {
			// If the current cost exceeds the best answer found, break out of the loop
			if cost > ans {
				break
			}
			// Update the cost based on the prefix sums
			cost += j * (xsum[k] - xsum[math.Max(k-i, 0)])
		}
		// Update the answer with the minimum cost found
		ans = math.Min(ans, cost)
	}

	// Output the final answer, which includes the base cost
	fmt.Println(ans + N*X)
}


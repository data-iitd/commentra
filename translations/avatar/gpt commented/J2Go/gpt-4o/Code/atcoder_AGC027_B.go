package main

import (
	"fmt"
)

const INF = int(^uint(0) >> 1) // Define a constant for infinity

func main() {
	solve()
}

func solve() {
	var N int
	var X int64
	fmt.Scan(&N, &X)

	x := make([]int64, N)
	xsum := make([]int64, N+1)

	// Read the elements into the array and compute the prefix sums
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
		xsum[i+1] = xsum[i] + x[i]
	}

	// Initialize the answer with the cost of processing all elements with the base cost
	ans := X*int64(N) + 5*xsum[N]

	// Iterate through possible splits of the array
	for i := 1; i < N; i++ {
		// Calculate the cost for the current split
		cost := X*int64(i) + 5*(xsum[N]-xsum[N-i])

		// Incrementally add costs based on the current split
		for j, k := int64(5), N-i; k >= 0; j += 2 {
			if cost > ans {
				break
			}
			cost += j * (xsum[k] - xsum[max(k-i, 0)])
			k -= i
		}
		// Update the answer with the minimum cost found
		if cost < ans {
			ans = cost
		}
	}

	// Output the final answer, which includes the base cost
	fmt.Println(ans + int64(N)*X)
}

// max function to return the maximum of two integers
func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

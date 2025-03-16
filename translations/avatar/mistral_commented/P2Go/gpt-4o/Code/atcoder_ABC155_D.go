package main

import (
	"fmt"
	"sort"
)

func main() {
	// Define input variables
	var N, K int
	fmt.Scan(&N, &K)

	// Initialize slice 'A' with input values
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	// Sort slice 'A' in ascending order
	sort.Ints(A)

	// Initialize variables for binary search
	ll := -1e18 - 1
	rr := 1e18 + 1

	// Perform binary search until 'll + 1' is less than 'rr'
	for ll+1 < rr {
		// Calculate mid value for binary search
		x := (ll + rr) / 2

		// Initialize variable 'tot' to store total count of elements
		tot := 0

		// Iterate through slice 'A' and calculate total count of elements that satisfy the condition
		for i := 0; i < N; i++ {
			// Check if current element 'A[i]' is negative
			if A[i] < 0 {
				// Initialize variables 'l' and 'r' for binary search in the range of indices
				l, r := 0, N

				// Perform binary search to find the index 'c' such that A[i] * A[c] >= x
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						l = c
					} else {
						r = c
					}
				}

				// Update 'tot' with the number of elements greater than 'c'
				tot += N - r
			} else {
				l, r := 0, N
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						l = c
					} else {
						r = c
					}
				}
				tot += r
			}

			// Update 'tot' with the contribution of current element 'A[i]'
			if A[i]*A[i] < x {
				tot--
			}
		}

		// Check if total count of elements is greater than or equal to 'K'
		if tot >= K {
			// Update 'll' if condition is satisfied
			ll = x
		} else {
			// Update 'rr' if condition is not satisfied
			rr = x
		}
	}

	// Print the final answer
	fmt.Println(ll)
}

// <END-OF-CODE>

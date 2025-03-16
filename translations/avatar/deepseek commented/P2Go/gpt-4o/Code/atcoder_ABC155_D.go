package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K) // Reading N and K
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i]) // Reading list A
	}
	sort.Ints(A) // Sorting the list A

	// Binary search setup
	ll := -1e18 - 1 // Lower limit initialized to a very small number
	rr := 1e18 + 1  // Upper limit initialized to a very large number

	// Binary search execution
	for ll+1 < rr {
		x := (ll + rr) / 2 // Calculating the midpoint of the current range
		tot := 0           // Initializing the total count of valid pairs

		// Counting valid pairs for each element in A
		for i := 0; i < N; i++ {
			if A[i] < 0 {
				l, r := -1, N
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						r = c
					} else {
						l = c
					}
				}
				tot += N - r // Updating the total count for negative A[i]
			} else {
				l, r := -1, N
				for l+1 < r {
					c := (l + r) / 2
					if A[i]*A[c] < x {
						l = c
					} else {
						r = c
					}
				}
				tot += r // Updating the total count for non-negative A[i]
			}

			if A[i]*A[i] < x {
				tot-- // Adjusting for the pair (i, i) if necessary
			}
		}

		tot /= 2 // Dividing by 2 to correct for double-counting pairs

		// Adjusting the search range based on the total count
		if tot < K {
			ll = x
		} else {
			rr = x
		}
	}

	fmt.Println(ll) // Output the result
}

// <END-OF-CODE>

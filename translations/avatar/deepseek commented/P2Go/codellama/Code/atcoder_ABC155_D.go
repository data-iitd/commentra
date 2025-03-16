package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	sort.Ints(A)

	// Binary search setup
	ll := -1000000000000000000 - 1
	rr := 1000000000000000000 + 1

	// Binary search execution
	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := 0

		// Counting valid pairs for each element in A
		for i := 0; i < N; i++ {
			if A[i] < 0 {
				l := -1
				r := N
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
				l := -1
				r := N
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


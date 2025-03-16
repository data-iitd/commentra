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

	ll := -1e18 - 1
	rr := 1e18 + 1

	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := 0

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
				tot += N - r
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
				tot += r
			}

			if A[i]*A[i] < x {
				tot -= 1
			}
		}

		tot /= 2

		if tot < K {
			ll = x
		} else {
			rr = x
		}
	}

	fmt.Println(ll)
}

// <END-OF-CODE>

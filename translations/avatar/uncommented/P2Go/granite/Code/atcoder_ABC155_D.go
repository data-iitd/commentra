
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	var N, K int
	fmt.Fscanf(in, "%d%d", &N, &K)
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(in, "%d", &A[i])
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i] < A[j]
	})
	ll, rr := int64(-1e18-1), int64(1e18+1)
	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := int64(0)
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
				tot += int64(N - r)
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
				tot += int64(r)
			}
			if A[i]*A[i] < x {
				tot--
			}
		}
		tot /= 2
		if tot < int64(K) {
			ll = x
		} else {
			rr = x
		}
	}
	fmt.Fprintln(out, ll)
	out.Flush()
}

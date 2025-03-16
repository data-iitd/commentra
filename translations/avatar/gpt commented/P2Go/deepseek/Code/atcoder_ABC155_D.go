package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, K int
	fmt.Fscan(reader, &N, &K)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &A[i])
	}
	sort.Ints(A)

	ll := int(-1e18) - 1
	rr := int(1e18) + 1

	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := 0

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
				tot += N - r
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
				tot += r
			}

			if A[i]*A[i] < x {
				tot--
			}
		}

		tot /= 2

		if tot < K {
			ll = x
		} else {
			rr = x
		}
	}

	fmt.Fprintln(writer, ll)
}


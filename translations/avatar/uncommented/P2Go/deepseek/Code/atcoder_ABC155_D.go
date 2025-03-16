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

	ll := int64(-1e18) - 1
	rr := int64(1e18) + 1

	for ll+1 < rr {
		x := (ll + rr) / 2
		tot := int64(0)
		for i := 0; i < N; i++ {
			if A[i] < 0 {
				l := -1
				r := N
				for l+1 < r {
					c := (l + r) / 2
					if int64(A[i])*int64(A[c]) < int64(x) {
						r = c
					} else {
						l = c
					}
				}
				tot += int64(N - r)
			} else {
				l := -1
				r := N
				for l+1 < r {
					c := (l + r) / 2
					if int64(A[i])*int64(A[c]) < int64(x) {
						l = c
					} else {
						r = c
					}
				}
				tot += int64(r)
			}
			if int64(A[i])*int64(A[i]) < int64(x) {
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
	fmt.Fprintln(writer, ll)
}


package main

import (
	"fmt"
	"os"
)

func solve(N, M, Q int, a, b, c, d []int) {
	res := 0

	var rec func(A []int)
	rec = func(A []int) {
		if len(A) == N {
			ans := 0
			for i := 0; i < Q; i++ {
				if A[b[i]-1]-A[a[i]-1] == c[i] {
					ans += d[i]
				}
			}
			if ans > res {
				res = ans
			}
			return
		}
		lastMax := 1
		if len(A) > 0 {
			lastMax = A[len(A)-1]
		}
		for i := lastMax; i <= M; i++ {
			rec(append(A, i))
		}
	}

	rec([]int{})
	fmt.Println(res)
}

func main() {
	var N, M, Q int
	fmt.Scan(&N, &M, &Q)

	a := make([]int, Q)
	b := make([]int, Q)
	c := make([]int, Q)
	d := make([]int, Q)

	for i := 0; i < Q; i++ {
		fmt.Scan(&a[i], &b[i], &c[i], &d[i])
	}

	solve(N, M, Q, a, b, c, d)
}

// <END-OF-CODE>

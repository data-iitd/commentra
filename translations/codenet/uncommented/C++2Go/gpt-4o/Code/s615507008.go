package main

import (
	"fmt"
)

func solve(N int64, T []int64, M int64, P []int64, X []int64) {
	for i := int64(0); i < M; i++ {
		ans := int64(0)
		for j := int64(0); j < N; j++ {
			if j == P[i]-1 {
				ans += X[i]
			} else {
				ans += T[j]
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	var N int64
	fmt.Scan(&N)
	T := make([]int64, N)
	for i := int64(0); i < N; i++ {
		fmt.Scan(&T[i])
	}
	var M int64
	fmt.Scan(&M)
	P := make([]int64, M)
	X := make([]int64, M)
	for i := int64(0); i < M; i++ {
		fmt.Scan(&P[i], &X[i])
	}
	solve(N, T, M, P, X)
}

// <END-OF-CODE>

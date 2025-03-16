package main

import (
	"fmt"
)

func solve(N int, T []int, M int, P []int, X []int) {
	for i := 0; i < M; i++ {
		ans := 0
		for j := 0; j < N; j++ {
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
	var N int
	fmt.Scan(&N)
	T := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&T[i])
	}
	var M int
	fmt.Scan(&M)
	P := make([]int, M)
	X := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Scan(&P[i], &X[i])
	}
	solve(N, T, M, P, X)
}


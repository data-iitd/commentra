package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	if possible(N, A) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func possible(N int, A []int) bool {
	var sum int64 = 0
	for i := 0; i < N; i++ {
		sum += int64(A[i])
	}
	NS := int64(N * (N + 1) / 2)
	if sum%NS != 0 {
		return false
	}
	K := sum / NS
	for i := 0; i < N; i++ {
		j := i - 1
		if i == 0 {
			j = N - 1
		}
		d := K - (int64(A[i]) - int64(A[j]))
		if d < 0 || d%int64(N) != 0 {
			return false
		}
	}
	return true
}

// <END-OF-CODE>

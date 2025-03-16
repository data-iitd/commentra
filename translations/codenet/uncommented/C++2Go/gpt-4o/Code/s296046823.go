package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)

	v := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&v[i])
	}

	// ceil((N-1) / (K-1))
	count := (N - 1 + (K - 2)) / (K - 1)
	fmt.Println(count)
}

// <END-OF-CODE>

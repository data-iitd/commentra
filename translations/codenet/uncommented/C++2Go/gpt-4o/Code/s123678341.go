package main

import (
	"fmt"
	"sort"
)

func main() {
	var X, Y, Z, K int
	fmt.Scan(&X, &Y, &Z, &K)

	A := make([]int64, X)
	B := make([]int64, Y)
	C := make([]int64, Z)

	for i := 0; i < X; i++ {
		fmt.Scan(&A[i])
	}
	for i := 0; i < Y; i++ {
		fmt.Scan(&B[i])
	}
	for i := 0; i < Z; i++ {
		fmt.Scan(&C[i])
	}

	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})
	sort.Slice(B, func(i, j int) bool {
		return B[i] > B[j]
	})
	sort.Slice(C, func(i, j int) bool {
		return C[i] > C[j]
	})

	AB := make([]int64, 0)
	for i := 0; i < X; i++ {
		for j := 0; j < Y; j++ {
			AB = append(AB, A[i]+B[j])
		}
	}

	sort.Slice(AB, func(i, j int) bool {
		return AB[i] > AB[j]
	})

	ABC := make([]int64, 0)
	for i := 0; i < min(K, len(AB)); i++ {
		for j := 0; j < Z; j++ {
			ABC = append(ABC, AB[i]+C[j])
		}
	}

	sort.Slice(ABC, func(i, j int) bool {
		return ABC[i] > ABC[j]
	})

	for i := 0; i < K; i++ {
		fmt.Println(ABC[i])
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>

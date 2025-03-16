package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, T int
	fmt.Scanf("%d %d", &N, &T)
	A := make([]int, N)
	B := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scanf("%d", &A[i])
	}
	m := A[0]
	B[1] = A[1] - m
	m = min(m, A[1])
	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = min(m, A[i])
	}
	fmt.Println(sort.Search(len(B), func(i int) bool { return B[i] == *max(B) }))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b *int) *int {
	if a > b {
		return a
	}
	return b
}


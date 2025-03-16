package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})
	var max int64 = math.MaxInt64
	var index int
	for i := 1; i < N; i++ {
		if max > int64(math.Abs(float64(A[0])-2*float64(A[i]))) {
			max = int64(math.Abs(float64(A[0]) - 2*float64(A[i])))
			index = i
		}
	}
	fmt.Println(A[0], A[index])
}


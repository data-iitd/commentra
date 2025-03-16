package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	var A [][]int
	for i := 0; i < N; i++ {
		var x int
		fmt.Scan(&x)
		A = append(A, []int{i + 1, x})
	}

	sort.Slice(A, func(i, j int) bool {
		return A[i][1] < A[j][1]
	})

	var A_ []int
	for _, a := range A {
		A_ = append(A_, a[0])
	}

	for i := 0; i < len(A_) - 1; i++ {
		fmt.Print(A_[i], " ")
	}
	fmt.Print(A_[len(A_)-1])
}


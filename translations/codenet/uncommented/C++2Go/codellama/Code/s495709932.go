package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	var answer int64
	for i := 0; i < N-1; i++ {
		for j := i + 1; j < N; j++ {
			diff := int64(math.Abs(float64(A[i] - A[j])))
			if diff > answer {
				answer = diff
			}
		}
	}
	fmt.Println(answer)
}


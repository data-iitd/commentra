
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scanf("%d", &N)
	var A [5]int
	for i := 0; i < 5; i++ {
		fmt.Scanf("%d", &A[i])
	}
	fmt.Printf("%d\n", int(math.Ceil(float64(N)/float64(min(A))))+4)
}

func min(A [5]int) int {
	min := A[0]
	for i := 1; i < 5; i++ {
		if A[i] < min {
			min = A[i]
		}
	}
	return min
}


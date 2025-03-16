
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, 5)
	for i := 0; i < 5; i++ {
		fmt.Scan(&A[i])
	}

	fmt.Println(int(math.Ceil(float64(N)/float64(min(A)))))
}

func min(A []int) int {
	min := A[0]
	for _, v := range A {
		if v < min {
			min = v
		}
	}
	return min
}


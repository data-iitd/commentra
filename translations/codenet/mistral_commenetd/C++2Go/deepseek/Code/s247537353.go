package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, C, K int
	fmt.Scan(&A, &B, &C, &K)

	if A+B >= K {
		fmt.Println(int(math.Min(float64(A), float64(K))))
	} else {
		fmt.Println(A - (K - (A + B)))
	}
}


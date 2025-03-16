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

	minA := A[0]
	for _, value := range A {
		if value < minA {
			minA = value
		}
	}

	result := int(math.Ceil(float64(N) / float64(minA))) + 4
	fmt.Println(result)
}

// <END-OF-CODE>

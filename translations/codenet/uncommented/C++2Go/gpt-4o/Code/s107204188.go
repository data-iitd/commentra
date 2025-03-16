package main

import (
	"fmt"
	"math"
)

func main() {
	minA := math.Pow(10, 9) + 1
	num := 0

	var n, t, f int
	fmt.Scan(&n, &t)
	A := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	for i := 0; i < n; i++ {
		if minA > float64(A[i]) {
			minA = float64(A[i])
		} else {
			if f == A[i]-int(minA) {
				num++
			} else if f < A[i]-int(minA) {
				num = 1
				f = A[i] - int(minA)
			}
		}
	}

	fmt.Println(num)
}

// <END-OF-CODE>

package main

import (
	"fmt"
	"math"
)

func main() {
	var minA int = int(math.Pow(10, 9) + 1)
	var num int = 0

	var n, t, f int = 0, 0, 0
	fmt.Scan(&n, &t)
	A := make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	for i := 0; i < n; i++ {
		if minA > A[i] {
			minA = A[i]
		} else {

			if f == A[i]-minA {
				num++
			} else if f < A[i]-minA {
				num = 1
				f = A[i] - minA
			}

		}
	}

	fmt.Println(num)

}


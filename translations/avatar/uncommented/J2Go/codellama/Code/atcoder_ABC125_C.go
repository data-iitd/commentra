
package main

import (
	"fmt"
	"math"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	M := make([]int, N)
	L := make([]int, N)
	R := make([]int, N)
	L[0] = A[0]
	for i := 1; i < N; i++ {
		L[i] = gcd(L[i-1], A[i])
	}
	R[N-1] = A[N-1]
	for i := N - 2; i >= 0; i-- {
		R[i] = gcd(R[i+1], A[i])
	}
	answer := math.Max(L[N-2], R[1])
	for i := 1; i < N-1; i++ {
		answer = math.Max(answer, gcd(L[i-1], R[i+1]))
	}
	fmt.Println(answer)
}

func gcd(a, b int) int {
	if b > a {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	r := -1
	for b != 0 {
		r = a % b
		a = b
		b = r
	}
	return a
}


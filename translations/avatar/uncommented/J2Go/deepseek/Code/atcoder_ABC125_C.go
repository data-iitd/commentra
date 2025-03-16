package main

import (
	"fmt"
	"math"
)

func gcd(a, b int) int {
	if b > a {
		a, b = b, a
	}
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
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
	answer := int(math.Max(float64(L[N-2]), float64(R[1])))
	for i := 1; i < N-1; i++ {
		answer = int(math.Max(float64(answer), float64(gcd(L[i-1], R[i+1]))))
	}
	fmt.Println(answer)
}


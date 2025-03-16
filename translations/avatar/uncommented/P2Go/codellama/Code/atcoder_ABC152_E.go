package main

import (
	"fmt"
	"math"
)

func lcm(a, b int) int {
	return a * b / gcd(a, b)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	_lcm := 1
	for _, a := range A {
		_lcm = lcm(_lcm, a)
	}
	ans := _lcm * pow(A, N-1, 1000000007)
	fmt.Println(ans % 1000000007)
}

func pow(A []int, n, m int) int {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return A[0]
	}
	if n%2 == 0 {
		return pow(A, n/2, m) * pow(A, n/2, m) % m
	}
	return pow(A, n-1, m) * A[0] % m
}


package main

import (
	"fmt"
	"math"
)

func lcm(a, b int) int {
	g := gcd(a, b)
	return a * b / g
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	MOD := 1000000007
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
	ans := _lcm * sum(A, MOD) % MOD
	fmt.Println(int(ans % MOD))
}

func sum(A []int, MOD int) int {
	var sum int
	for _, a := range A {
		sum += pow(a, MOD-2, MOD)
	}
	return sum
}

func pow(a, b, MOD int) int {
	if b == 0 {
		return 1
	}
	if b%2 == 0 {
		return pow(a, b/2, MOD) * pow(a, b/2, MOD) % MOD
	}
	return a * pow(a, b-1, MOD) % MOD
}


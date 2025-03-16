package main

import (
	"fmt"
	"math"
	"strconv"
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
	MOD := 1000000007
	N := nextInt()
	A := make([]int, N)
	for i := 0; i < N; i++ {
		A[i] = nextInt()
	}

	_lcm := 1
	for _, a := range A {
		_lcm = lcm(_lcm, a)
	}

	ans := _lcm * sum(A) % MOD
	fmt.Println(ans)
}

func nextInt() int {
	var n int
	fmt.Scan(&n)
	return n
}

func sum(A []int) int {
	var s int
	for _, a := range A {
		s += pow(a, MOD-2, MOD)
	}
	return s
}

func pow(a, b, m int) int {
	if b == 0 {
		return 1
	}
	if b%2 == 0 {
		return pow(a*a%m, b/2, m)
	}
	return a * pow(a, b-1, m) % m
}


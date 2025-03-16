package main

import (
	"fmt"
	"strings"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	gcd := 0
	for i := 0; i < N; i++ {
		gcd = gcd(gcd, A[i])
	}
	fmt.Println(gcd)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}


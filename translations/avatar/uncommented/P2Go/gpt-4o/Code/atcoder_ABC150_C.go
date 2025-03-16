package main

import (
	"fmt"
	"math/big"
	"os"
)

func factorial(n int) *big.Int {
	if n == 0 {
		return big.NewInt(1)
	}
	result := big.NewInt(1)
	for i := 1; i <= n; i++ {
		result.Mul(result, big.NewInt(int64(i)))
	}
	return result
}

func permutations(n int) [][]int {
	if n == 0 {
		return [][]int{{}}
	}
	result := [][]int{}
	for i := 0; i < n; i++ {
		for _, perm := range permutations(n - 1) {
			result = append(result, append(append([]int{}, i+1), perm...))
		}
	}
	return result
}

func indexOf(slice [][]int, item []int) int {
	for i, v := range slice {
		if equal(v, item) {
			return i
		}
	}
	return -1
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func main() {
	var n int
	fmt.Scan(&n)

	orig := permutations(n)

	p := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	q := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&q[i])
	}

	pn := indexOf(orig, p)
	qn := indexOf(orig, q)

	fmt.Println(abs(pn - qn))
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// <END-OF-CODE>

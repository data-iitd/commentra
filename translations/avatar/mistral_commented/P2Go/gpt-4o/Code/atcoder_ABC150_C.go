package main

import (
	"fmt"
	"math/big"
	"os"
)

func factorial(n int64) *big.Int {
	if n == 0 {
		return big.NewInt(1)
	}
	result := big.NewInt(1)
	for i := int64(1); i <= n; i++ {
		result.Mul(result, big.NewInt(i))
	}
	return result
}

func permutations(arr []int, start int, result *[][]int) {
	if start == len(arr)-1 {
		perm := make([]int, len(arr))
		copy(perm, arr)
		*result = append(*result, perm)
		return
	}
	for i := start; i < len(arr); i++ {
		arr[start], arr[i] = arr[i], arr[start]
		permutations(arr, start+1, result)
		arr[start], arr[i] = arr[i], arr[start] // backtrack
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	// Create a slice of numbers from 1 to n
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = i + 1
	}

	// Generate all permutations
	var orig [][]int
	permutations(arr, 0, &orig)

	// Read two permutations from the user
	var p, q []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		p = append(p, num)
	}
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num)
		q = append(q, num)
	}

	// Find the indices of p and q in the orig list
	var pn, qn int
	for i, perm := range orig {
		if equal(perm, p) {
			pn = i
		}
		if equal(perm, q) {
			qn = i
		}
	}

	// Print the absolute difference between the indices of p and q
	fmt.Println(abs(pn - qn))
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

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

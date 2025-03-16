package main

import (
	"fmt"
	"math/big"
	"sort"
)

func permutations(arr []int) [][]int {
	var result [][]int
	var helper func([]int, int)
	helper = func(arr []int, n int) {
		if n == 1 {
			perm := make([]int, len(arr))
			copy(perm, arr)
			result = append(result, perm)
			return
		}
		for i := 0; i < n; i++ {
			helper(arr, n-1)
			if n%2 == 0 {
				arr[i], arr[n-1] = arr[n-1], arr[i]
			} else {
				arr[0], arr[n-1] = arr[n-1], arr[0]
			}
		}
	}
	helper(arr, len(arr))
	return result
}

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input `n`

	// Generate all permutations of numbers from 1 to `n`
	arr := make([]int, n)
	for i := 1; i <= n; i++ {
		arr[i-1] = i
	}
	orig := permutations(arr)

	var p, q []int
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num) // Take the first permutation `p`
		p = append(p, num)
	}
	for i := 0; i < n; i++ {
		var num int
		fmt.Scan(&num) // Take the second permutation `q`
		q = append(q, num)
	}

	// Find the index of permutation `p` and `q` in the list of all permutations
	pn := -1
	qn := -1
	for i, perm := range orig {
		if equal(perm, p) {
			pn = i
		}
		if equal(perm, q) {
			qn = i
		}
	}

	// Calculate the absolute difference between the indices and print the result
	fmt.Println(abs(pn - qn))
}

// Function to check if two slices are equal
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

// Function to calculate the absolute value
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

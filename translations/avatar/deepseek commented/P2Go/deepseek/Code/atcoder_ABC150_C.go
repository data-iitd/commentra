package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n) // Take an integer input `n`

	// Generate all permutations of numbers from 1 to `n`
	var orig [][]int
	var permute func([]int, int)
	permute = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			orig = append(orig, tmp)
		} else {
			for i := 0; i < n; i++ {
				permute(arr, n-1)
				if n%2 == 1 {
					arr[0], arr[n-1] = arr[n-1], arr[0]
				} else {
					arr[i], arr[n-1] = arr[n-1], arr[i]
				}
			}
		}
	}
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = i + 1
	}
	permute(arr, n)

	// Take the first permutation `p` as a slice of integers
	var p []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		p = append(p, x)
	}

	// Take the second permutation `q` as a slice of integers
	var q []int
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		q = append(q, x)
	}

	// Find the index of permutation `p` in the list of all permutations
	pn := -1
	for i := 0; i < len(orig); i++ {
		if equal(orig[i], p) {
			pn = i
		}
	}

	// Find the index of permutation `q` in the list of all permutations
	qn := -1
	for i := 0; i < len(orig); i++ {
		if equal(orig[i], q) {
			qn = i
		}
	}

	// Calculate the absolute difference between the indices and print the result
	fmt.Println(math.Abs(float64(pn - qn)))
}

// Helper function to check if two slices are equal
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

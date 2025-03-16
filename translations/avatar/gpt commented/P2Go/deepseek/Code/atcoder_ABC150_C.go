package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Generate all possible permutations of the numbers from 1 to n
	var orig [][]int
	for _, perm := range permutations(n) {
		orig = append(orig, perm)
	}

	// Read the first permutation input as a slice of integers
	var p []int
	fmt.Scan(&p)

	// Read the second permutation input as a slice of integers
	var q []int
	fmt.Scan(&q)

	// Find the index of the first permutation in the list of all permutations
	pn := findIndex(orig, p)

	// Find the index of the second permutation in the list of all permutations
	qn := findIndex(orig, q)

	// Calculate and print the absolute difference between the two indices
	fmt.Println(abs(pn - qn))
}

// Helper function to generate all permutations of numbers from 1 to n
func permutations(n int) [][]int {
	var result [][]int
	var permute func([]int, int)
	permute = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			result = append(result, tmp)
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
	return result
}

// Helper function to find the index of a permutation in the list of all permutations
func findIndex(perms [][]int, perm []int) int {
	for i, p := range perms {
		if equal(p, perm) {
			return i
		}
	}
	return -1
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

// Helper function to calculate the absolute difference between two integers
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

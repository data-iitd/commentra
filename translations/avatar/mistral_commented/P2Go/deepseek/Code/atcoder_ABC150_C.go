package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Create a slice to hold all permutations
	var orig [][]int

	// Generate all permutations of numbers from 1 to n
	generatePermutations(1, n, []int{}, &orig)

	// Read two permutations as strings
	var pStr, qStr string
	fmt.Scan(&pStr)
	fmt.Scan(&qStr)

	// Convert permutation strings to tuples
	p := stringToTuple(pStr)
	q := stringToTuple(qStr)

	// Find the indices of p and q in the orig slice
	pn := findIndex(orig, p)
	qn := findIndex(orig, q)

	// Print the absolute difference between the indices of p and q
	fmt.Println(abs(pn - qn))
}

// Helper function to generate all permutations of numbers from start to end
func generatePermutations(start, end int, current []int, orig *[][]int) {
	if start > end {
		perm := make([]int, len(current))
		copy(perm, current)
		*orig = append(*orig, perm)
		return
	}
	for i := start; i <= end; i++ {
		current = append(current, i)
		generatePermutations(start+1, end, current, orig)
		current = current[:len(current)-1]
	}
}

// Helper function to convert a string permutation to a tuple
func stringToTuple(s string) []int {
	parts := strings.Split(s, " ")
	tuple := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		tuple[i] = num
	}
	return tuple
}

// Helper function to find the index of a permutation in the orig slice
func findIndex(orig [][]int, target []int) int {
	for i, perm := range orig {
		if equal(perm, target) {
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

// Helper function to calculate the absolute difference
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

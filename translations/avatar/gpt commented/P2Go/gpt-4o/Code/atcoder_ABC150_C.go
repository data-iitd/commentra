package main

import (
	"fmt"
	"math/big"
	"os"
	"strconv"
	"strings"
)

// Function to generate all permutations of a slice of integers
func permute(nums []int) [][]int {
	var result [][]int
	var backtrack func(start int)
	backtrack = func(start int) {
		if start == len(nums) {
			perm := make([]int, len(nums))
			copy(perm, nums)
			result = append(result, perm)
			return
		}
		for i := start; i < len(nums); i++ {
			nums[start], nums[i] = nums[i], nums[start]
			backtrack(start + 1)
			nums[start], nums[i] = nums[i], nums[start] // backtrack
		}
	}
	backtrack(0)
	return result
}

func main() {
	// Read an integer input n
	var n int
	fmt.Scan(&n)

	// Generate all possible permutations of the numbers from 1 to n
	nums := make([]int, n)
	for i := 1; i <= n; i++ {
		nums[i-1] = i
	}
	permutations := permute(nums)

	// Read the first permutation input as a slice of integers
	var pInput string
	fmt.Scan(&pInput)
	pStr := strings.Split(pInput, " ")
	p := make([]int, len(pStr))
	for i, s := range pStr {
		p[i], _ = strconv.Atoi(s)
	}

	// Read the second permutation input as a slice of integers
	var qInput string
	fmt.Scan(&qInput)
	qStr := strings.Split(qInput, " ")
	q := make([]int, len(qStr))
	for i, s := range qStr {
		q[i], _ = strconv.Atoi(s)
	}

	// Find the index of the first permutation in the list of all permutations
	var pn, qn int
	for i, perm := range permutations {
		if equal(perm, p) {
			pn = i
		}
		if equal(perm, q) {
			qn = i
		}
	}

	// Calculate and print the absolute difference between the two indices
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

// Function to calculate the absolute value of an integer
func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
